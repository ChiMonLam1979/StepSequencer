
#include "StepSequencerEngine.h"
#include "StepSequencerEditor.h"
#include "Extensions.h"
#include "Parameters.h"

StepSequencerEngine::StepSequencerEngine() : AudioProcessor (BusesProperties().withInput("Input",  AudioChannelSet::stereo(), true)),
treeState(*this, nullptr, "PARAMETERS", createParameterLayout())
{
	treeState.state = ValueTree(IDs::TreeStateID);

	for(auto& ID: IDs::StepEncoderIDs)
	{
		treeState.addParameterListener(ID, &noteHandler);
	}
}

AudioProcessorValueTreeState::ParameterLayout StepSequencerEngine::createParameterLayout()
{
	std::vector<std::unique_ptr<RangedAudioParameter>> parameters;

	for(auto i = 0; i < 16; i++)
	{
		auto stepEncoderParameter = std::make_unique<AudioParameterInt>(IDs::StepEncoderIDs[i], ParameterNames::StepEncoderNames[i], 0, 127, 0);

		parameters.push_back(std::move(stepEncoderParameter));

		auto stepButtonParameter = std::make_unique<AudioParameterBool>(IDs::StepButtonIDs[i], ParameterNames::StepButtonNames[i], false);

		parameters.push_back(std::move(stepButtonParameter));
	}

	return { parameters.begin(), parameters.end() };
}

StepSequencerEngine::~StepSequencerEngine()
{
}

AudioProcessorEditor* StepSequencerEngine::createEditor()
{
	return new StepSequencerEditor(*this);
}

void StepSequencerEngine::prepareToPlay (double sampleRate, int samplesPerBlock)
{
	rate = sampleRate;
}

void StepSequencerEngine::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
	auto playHead = getPlayHead();

	if (playHead == nullptr) return;

	AudioPlayHead::CurrentPositionInfo positionInfo{};

	playHead->getCurrentPosition(positionInfo);

	shouldFlash.store(true);


	// set led index - delay is added because UI is not in sync - just reaper?
	auto delay = 1;
	auto pos = std::floor((positionInfo.ppqPosition * 4 ) - delay);
	auto index = maths::mod(pos, 16);
	playPositionIndex.store(index);

	auto bpm = positionInfo.bpm;															// bpm is quarterNotesPerMinute
	auto bps = bpm / 60;																	// bps is quarterNotesPerSecond
	auto samplesPerBeat = rate / bps;														// number of samples per beat/quarternote is samples per sec / beats per second

	auto noteDivisionFactor = 4.0f;
	auto lengthFactor = 0.8f;

	auto samplesPerNoteDivision = samplesPerBeat / noteDivisionFactor;						// set note division
	auto noteLength = static_cast<int> (std::ceil(samplesPerNoteDivision * lengthFactor));	// set note length

	auto numSamples = buffer.getNumSamples();	// number of samples in each buffer

	//work out which notes will occur in the buffer
	const double ppqBegin = positionInfo.ppqPosition * noteDivisionFactor;
	const auto ppqEnd = ppqBegin + (numSamples / samplesPerNoteDivision);
	const int ippqBegin = std::ceil(maths::precisionRound(ppqBegin, 0.001));
	int ippqEnd = std::floor(ppqEnd);
	ippqEnd = positionInfo.isLooping ? maths::mod(ippqEnd, noteDivisionFactor * 4) : ippqEnd;

	midiTrack.notes[0]	= 34;
	midiTrack.notes[1]	= 34;
	midiTrack.notes[2]	= 34;
	midiTrack.notes[3]	= 36;
	midiTrack.notes[4]	= 37;
	midiTrack.notes[5]	= 34;
	midiTrack.notes[6]	= 41;
	midiTrack.notes[7]	= 34;
	midiTrack.notes[8]	= 37;
	midiTrack.notes[9]	= 34;
	midiTrack.notes[10]	= 34;
	midiTrack.notes[11]	= 34;
	midiTrack.notes[12]	= 41;
	midiTrack.notes[13]	= 34;
	midiTrack.notes[14]	= 34;
	midiTrack.notes[15]	= 34;
	
	midiTrack.velocity[0] = 34;
	midiTrack.velocity[1] = 34;
	midiTrack.velocity[2] = 0;
	midiTrack.velocity[3] = 34;
	midiTrack.velocity[4] = 34;
	midiTrack.velocity[5] = 0;
	midiTrack.velocity[6] = 34;
	midiTrack.velocity[7] = 0;
	midiTrack.velocity[8] = 34;
	midiTrack.velocity[9] = 0;
	midiTrack.velocity[10] = 0;
	midiTrack.velocity[11] = 0;
	midiTrack.velocity[12] = 34;
	midiTrack.velocity[13] = 0;
	midiTrack.velocity[14] = 0;
	midiTrack.velocity[15] = 0;

	// ppqPosition is only changing when the transport is playing.
	if (positionInfo.isPlaying)
	{
		samplesSinceNoteOn = (samplesSinceNoteOn + numSamples);	// update elapsed time since note-off of last buffer

		if (samplesSinceNoteOn >= noteLength && lastNoteValue > 0)	// check if last note was a note-on. if true we need to add a note off inside this buffer
		{
			auto offsetForNoteOff = jmin((numSamples - (samplesSinceNoteOn - noteLength)), numSamples - 1);

			midiMessages.addEvent(MidiMessage::noteOff(1, lastNoteValue), offsetForNoteOff);
			lastNoteValue = -1;
		}

		// for each note transition in the buffer...
		for (int i = ippqBegin; i <= ippqEnd; ++i)
		{
			 int offset = (int)samplesPerNoteDivision * (i - ppqBegin);

			if (!midiTrack.notes.empty()) // if there are notes in 'notes' coolection
			{
				index = std::fmod(i, midiTrack.notes.size());

				lastNoteValue = midiTrack.notes[index];  // set flag that last note was a note-on
				auto velocity = midiTrack.velocity[index];

				currentNoteIndex = (currentNoteIndex + 1) % midiTrack.notes.size();  // advance to next note in collection

				midiMessages.addEvent(MidiMessage::noteOn(1, lastNoteValue, velocity), offset); // add last note to buffer at sample pos = offset

				samplesSinceNoteOn = numSamples - offset;
			}

			if (samplesSinceNoteOn >= noteLength)		// check if note-off should occur within this buffer
			{
				auto OffsetForNoteOff = jmin((offset + noteLength), numSamples - 1);

				midiMessages.addEvent(MidiMessage::noteOff(1, lastNoteValue), OffsetForNoteOff);
				lastNoteValue = -1;		// set flag that last note was a note-off
			}
		}
	}

	if(!positionInfo.isPlaying)
	{
	}
}