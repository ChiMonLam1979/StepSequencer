#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class StepHandler : public AudioProcessorValueTreeState::Listener
{
public:

	StepHandler(std::vector<bool>& gates);
	~StepHandler();

	std::vector<bool>& gates;

private:

	void parameterChanged(const String& parameterID, float newValue) override;
};