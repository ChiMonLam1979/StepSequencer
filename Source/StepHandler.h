#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class StepHandler : public AudioProcessorValueTreeState::Listener
{
public:

	StepHandler();
	~StepHandler();

private:

	void parameterChanged(const String& parameterID, float newValue) override;
};