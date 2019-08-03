#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class StepChoicesHandler : public AudioProcessorValueTreeState::Listener
{
public:

	StepChoicesHandler();
	~StepChoicesHandler();

private:

	void parameterChanged(const String& parameterID, float newValue) override;

};