#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class PatternLengthDecHandler : public AudioProcessorValueTreeState::Listener
{
public:

	PatternLengthDecHandler(int& patternLength);

	~PatternLengthDecHandler();

private:

	int& patternLength;

	void parameterChanged(const String& parameterID, float newValue) override;

};