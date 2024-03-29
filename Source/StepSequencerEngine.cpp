
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
}

void StepSequencerEngine::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
	auto playHead = getPlayHead();

	if (playHead == nullptr) return;

	AudioPlayHead::CurrentPositionInfo positionInfo{};

	playHead->getCurrentPosition(positionInfo);

	shouldFlash.store(true);
	playPositionIndex.store(std::fmod(positionInfo.ppqPosition * 4, 16));
}