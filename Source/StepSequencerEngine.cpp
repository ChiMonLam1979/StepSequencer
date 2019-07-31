
#include "StepSequencerEngine.h"
#include "StepSequencerEditor.h"
#include "Extensions.h"

StepSequencerEngine::StepSequencerEngine() : AudioProcessor (BusesProperties().withInput("Input",  AudioChannelSet::stereo(), true))
{
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

	midiData.notes[0]	= 34;
	midiData.notes[1]	= 34;
	midiData.notes[2]	= 34;
	midiData.notes[3]	= 36;
	midiData.notes[4]	= 37;
	midiData.notes[5]	= 34;
	midiData.notes[6]	= 41;
	midiData.notes[7]	= 34;
	midiData.notes[8]	= 37;
	midiData.notes[9]	= 34;
	midiData.notes[10]	= 34;
	midiData.notes[11]	= 34;
	midiData.notes[12]	= 41;
	midiData.notes[13]	= 34;
	midiData.notes[14]	= 34;
	midiData.notes[15]	= 34;
	
	midiData.velocity[0] = 34;
	midiData.velocity[1] = 34;
	midiData.velocity[2] = 0;
	midiData.velocity[3] = 34;
	midiData.velocity[4] = 34;
	midiData.velocity[5] = 0;
	midiData.velocity[6] = 34;
	midiData.velocity[7] = 0;
	midiData.velocity[8] = 34;
	midiData.velocity[9] = 0;
	midiData.velocity[10] = 0;
	midiData.velocity[11] = 0;
	midiData.velocity[12] = 34;
	midiData.velocity[13] = 0;
	midiData.velocity[14] = 0;
	midiData.velocity[15] = 0;

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

			if (midiData.notes.size() > 0) // if there are notes in 'notes' coolection
			{
				index = std::fmod(i, midiData.notes.size());

				lastNoteValue = midiData.notes[index];  // set flag that last note was a note-on
				auto velocity = midiData.velocity[index];

				currentNoteIndex = (currentNoteIndex + 1) % midiData.notes.size();  // advance to next note in collection

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