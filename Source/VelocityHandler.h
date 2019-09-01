#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "ParameterIds.h"

class VelocityHandler : public AudioProcessorValueTreeState::Listener
{
public:

	VelocityHandler(std::vector<uint8>& velocities);

	~VelocityHandler();

	std::vector<uint8>& velocities;

private:

	void parameterChanged(const String& parameterID, float newValue) override;
};