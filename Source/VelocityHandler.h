#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class VelocityHandler : public AudioProcessorValueTreeState::Listener
{
public:

	VelocityHandler();
	~VelocityHandler();

private:

	void parameterChanged(const String& parameterID, float newValue) override;

};