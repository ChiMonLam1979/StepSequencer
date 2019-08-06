#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class NoteLengthHandler : public AudioProcessorValueTreeState::Listener
{
public:

	NoteLengthHandler();
	~NoteLengthHandler();

	std::vector<int> noteLengths;

private:

	void parameterChanged(const String& parameterID, float newValue) override;

};