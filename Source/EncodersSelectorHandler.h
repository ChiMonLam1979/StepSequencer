#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class EncodersSelectorHandler : public AudioProcessorValueTreeState::Listener
{
public:

	EncodersSelectorHandler();
	~EncodersSelectorHandler();

private:

	void parameterChanged(const String& parameterID, float newValue) override;
	
};