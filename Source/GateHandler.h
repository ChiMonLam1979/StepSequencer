#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class GateHandler : public AudioProcessorValueTreeState::Listener
{
public:

	GateHandler(std::vector<bool>& gates);
	~GateHandler();

	std::vector<bool>& gates;

private:

	void parameterChanged(const String& parameterID, float newValue) override;
};