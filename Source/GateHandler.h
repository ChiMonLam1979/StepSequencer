#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "ParameterIds.h"

class GateHandler : public AudioProcessorValueTreeState::Listener
{
public:

	GateHandler(std::vector<bool>& gates);

	~GateHandler();

	std::vector<bool>& gates;

private:

	void parameterChanged(const String& parameterID, float newValue) override;

	const String& genericParameterID{ IDs::StepButtonID };
};
