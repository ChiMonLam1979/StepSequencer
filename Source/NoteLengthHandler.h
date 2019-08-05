#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class NoteLengthHandler : public AudioProcessorValueTreeState::Listener
{
public:

	NoteLengthHandler();
	~NoteLengthHandler();

	void parameterChanged(const String& parameterID, float newValue) override;

private:

};