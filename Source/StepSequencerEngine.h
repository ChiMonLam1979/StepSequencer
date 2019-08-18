#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "NoteHandler.h"
#include "StepHandler.h"
#include "VelocityHandler.h"
#include "StepChoicesHandler.h"
#include "NoteLengthHandler.h"
#include "Pattern.h"
#include "PatternService.h"
#include "EncodersSelectorHandler.h"

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

	double	rate					{ 0	};
	int		samplesSinceNoteOn		{ 0	};
	int		currentNoteIndex		{ 0	};
	int		lastNoteValue			{ -1 };
	double	samplesPerNoteDivision	{ 0 };

	Pattern	pattern				{16, 1};

	NoteHandler				noteHandler			{ pattern.notes };
	StepHandler				stepHandler			{ pattern.gates };
	NoteLengthHandler		noteLengthHandler	{ pattern.noteLengths, samplesPerNoteDivision };

	VelocityHandler			velocityHandler		{ pattern.velocities };
	StepChoicesHandler		stepChoicesHandler;
	EncodersSelectorHandler	encodersSelectorHandler;

	PatternService patternService{ pattern, noteHandler, noteLengthHandler, velocityHandler, stepHandler };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StepSequencerEngine)
};
