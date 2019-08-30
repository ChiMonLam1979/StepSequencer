
#include "StepSequencerEngine.h"
#include "StepSequencerEditor.h"
#include "Extensions.h"
#include "ParameterIds.h"

StepSequencerEngine::StepSequencerEngine() : AudioProcessor (BusesProperties().withInput("Input",  AudioChannelSet::stereo(), true)),
treeState(*this, nullptr, "PARAMETERS", createParameterLayout())
{
	treeState.state = ValueTree(IDs::TreeStateID);

	for(auto& ID: IDs::PitchEncoderIDs)
	{
		treeState.addParameterListener(ID, &noteHandler);
	}

	for(auto& ID: IDs::StepButtonIDs)
	{
		treeState.addParameterListener(ID, &gateHandler);
	}

	for (auto& ID : IDs::NoteLengthEncoderIDs)
	{
		treeState.addParameterListener(ID, &noteLengthHandler);
	}

	for(auto& ID: IDs::VelocityEncoderIDs)
	{
		treeState.addParameterListener(ID, &velocityHandler);
	}
}

AudioProcessorValueTreeState::ParameterLayout StepSequencerEngine::createParameterLayout()
{
	auto parameters = parametersFactory.CreateParameters();

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
	auto delay	= 1;
	auto pos	= std::floor((positionInfo.ppqPosition * 4 ) - delay);
	auto index	= maths::mod(pos, 16);
	playPositionIndex.store(index);

	auto bpm			= positionInfo.bpm;													// bpm is quarterNotesPerMinute
	auto bps			= bpm / 60;															// bps is quarterNotesPerSecond
	auto samplesPerBeat	= rate / bps;														// number of samples per beat/quarternote is samples per sec / beats per second

	auto noteDivisionFactor	= 4.0f;
	auto lengthFactor		= 0.8f;

	samplesPerNoteDivision = samplesPerBeat / noteDivisionFactor;
	auto noteLength				= static_cast<int> (std::ceil(samplesPerNoteDivision * lengthFactor));	// set note length

	auto numSamples = buffer.getNumSamples();	// number of samples in each buffer

	//work out which notes will occur in the buffer
	const double	ppqBegin	= positionInfo.ppqPosition * noteDivisionFactor;
	const auto		ppqEnd		= ppqBegin + (numSamples / samplesPerNoteDivision);
	const int		ippqBegin	= std::ceil(maths::precisionRound(ppqBegin, 0.001));
	int				ippqEnd		= std::floor(ppqEnd);
					ippqEnd		= positionInfo.isLooping ? maths::mod(ippqEnd, noteDivisionFactor * 4) : ippqEnd;

	auto pattern = patternService.GetPattern(); //load the pattern to play


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
		 	 index = std::fmod(i, pattern.notes.size());

			 int offset = (int)samplesPerNoteDivision * (i - ppqBegin);

			if (!pattern.notes.empty() && pattern.gates[index]) // if there are notes in the track
			{
				lastNoteValue = pattern.notes[index];  // set flag that last note was a note-on or not
				auto velocity = pattern.velocities[index];

				currentNoteIndex = (currentNoteIndex + 1) % pattern.notes.size();  // advance to next note in track

				midiMessages.addEvent(MidiMessage::noteOn(1, lastNoteValue, velocity), offset); // add last note to buffer at sample pos = offset

				samplesSinceNoteOn = numSamples - offset;
			}

			if (samplesSinceNoteOn >= noteLength && lastNoteValue > 0)		// check if note-off should occur within this buffer
			{
				auto OffsetForNoteOff = jmin((offset + noteLength), numSamples - 1);

				midiMessages.addEvent(MidiMessage::noteOff(1, lastNoteValue), OffsetForNoteOff);
				lastNoteValue = -1;		// set flag that last note was a note-off
			}
		}
	}

	if(!positionInfo.isPlaying)
	{
		//remove the hacky delay
		pos	= std::floor((positionInfo.ppqPosition * 4));
		index	= maths::mod(pos, 16);
		playPositionIndex.store(index);
	}
}