#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "MidiTrack.h"
#include "NoteHandler.h"

class StepSequencerEngine  : public AudioProcessor
{
public:

	StepSequencerEngine();
    ~StepSequencerEngine();

	void prepareToPlay(double sampleRate, int) override;
	void releaseResources() override {}
	void processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages) override;
	bool isMidiEffect() const override { return true; }

    AudioProcessorEditor* createEditor() override;
	bool hasEditor() const override { return true; }

	const String getName() const override { return "StepSequencer"; }

	bool acceptsMidi() const override { return true; }
	bool producesMidi() const override { return true; }
	double getTailLengthSeconds() const override { return 0; }

	int getNumPrograms() override { return 1; }
	int getCurrentProgram() override { return 0; }
	void setCurrentProgram(int) override {}
	const String getProgramName(int) override { return {}; }
	void changeProgramName(int, const String&) override {}

	void getStateInformation(MemoryBlock& destData) override {};
	void setStateInformation(const void* data, int sizeInBytes) override {};

	AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

	AudioProcessorValueTreeState treeState;

	std::atomic<bool>	shouldFlash			{ false };
	std::atomic<int>	playPositionIndex	{ 0 };

private:

	double rate	{ 0 };
	int samplesSinceNoteOn{ 0 };
	int lastNoteValue{ -1 };
	int currentNoteIndex{ 0 };

	MidiTrack midiTrack{16, 1};
	NoteHandler noteHandler;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StepSequencerEngine)
};
