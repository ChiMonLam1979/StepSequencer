
#include "StepSequencerEngine.h"
#include "StepSequencerEditor.h"

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
	currentNote = 0;
	lastNoteValue = -1;
	rate = sampleRate;
	samplesSinceNoteOn = 0;
}

void StepSequencerEngine::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
	auto playHead = getPlayHead();

	if (playHead == nullptr) return;

	AudioPlayHead::CurrentPositionInfo positionInfo{};

	playHead->getCurrentPosition(positionInfo);

	shouldFlash.store(true);

	playPositionIndex.store(std::fmod(positionInfo.ppqPosition * 4, 16));

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
	const int ippqBegin = std::ceil(ppqBegin);

	int ippqEnd = positionInfo.isLooping ? ((int)std::floor(ppqEnd) % (4 * (int)noteDivisionFactor)) : (int)std::floor(ppqEnd);

	midiData.notes[0]	= 34;
	midiData.notes[1]	= 34;
	midiData.notes[2]	= 34;
	midiData.notes[3]	= 34;
	midiData.notes[4]	= 34;
	midiData.notes[5]	= 34;
	midiData.notes[6]	= 34;
	midiData.notes[7]	= 34;
	midiData.notes[8]	= 34;
	midiData.notes[9]	= 34;
	midiData.notes[10]	= 34;
	midiData.notes[11]	= 34;
	midiData.notes[12]	= 34;
	midiData.notes[13]	= 34;
	midiData.notes[14]	= 34;
	midiData.notes[15]	= 34;

	midiData.velocity[0]	= 34;
	midiData.velocity[1]	= 34;
	midiData.velocity[2]	= 34;
	midiData.velocity[3]	= 34;
	midiData.velocity[4]	= 34;
	midiData.velocity[5]	= 34;
	midiData.velocity[6]	= 34;
	midiData.velocity[7]	= 34;
	midiData.velocity[8]	= 34;
	midiData.velocity[9]	= 34;
	midiData.velocity[10]	= 34;
	midiData.velocity[11]	= 34;
	midiData.velocity[12]	= 34;
	midiData.velocity[13]	= 34;
	midiData.velocity[14]	= 34;
	midiData.velocity[15]	= 34;

	// ppqPosition is only changing when the transport is playing.
	if (positionInfo.isPlaying)
	{
		samplesSinceNoteOn = (samplesSinceNoteOn + numSamples);	// update elapsed time since note-off 

		if (samplesSinceNoteOn >= noteLength && lastNoteValue > 0)	// check if last note was a note-on. if true we need to add a note off inside this buffer
		{
			auto offsetForNoteOff = jmin((numSamples - (samplesSinceNoteOn - noteLength)), numSamples - 1);

			midiMessages.addEvent(MidiMessage::noteOff(1, lastNoteValue), offsetForNoteOff);
			lastNoteValue = -1;
		}

		// for each note transition in the buffer...
		for (int i = ippqBegin; i <= ippqEnd; ++i)
		{
			//work out the exact sample where the note occurs
			const int offset = (int)samplesPerNoteDivision * (i - ppqBegin);

			if (midiData.notes.size() > 0) // if there are notes in 'notes' coolection
			{
				lastNoteValue = midiData.notes[currentNote];  // set flag that last note was a note-on
				auto velocity = midiData.velocity[currentNote];

				currentNote = (currentNote + 1) % midiData.notes.size();  // advance to next note in collection

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