#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class VelocityHandler : public AudioProcessorValueTreeState::Listener
{
public:

	VelocityHandler();
	~VelocityHandler();

	std::vector<uint8> velocities;

private:

	void parameterChanged(const String& parameterID, float newValue) override;

};