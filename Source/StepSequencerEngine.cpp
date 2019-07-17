
#include "StepSequencerEngine.h"
#include "StepSequencerEditor.h"

StepSequencerEngine::StepSequencerEngine() : AudioProcessor (BusesProperties().withInput("Input",  AudioChannelSet::stereo(), true))
{
}

StepSequencerEngine::~StepSequencerEngine()
{
}

StepSequencerEngine* JUCE_CALLTYPE createPluginFilter()
{
	return new StepSequencerEngine();
}

AudioProcessorEditor* StepSequencerEngine::createEditor()
{
	return new StepSequencerEditor(*this);
}

void StepSequencerEngine::prepareToPlay (double sampleRate, int samplesPerBlock)
{
}

void StepSequencerEngine::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
}