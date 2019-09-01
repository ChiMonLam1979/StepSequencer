#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class PatternLengthIncHandler : public AudioProcessorValueTreeState::Listener
{
public:

	PatternLengthIncHandler(int& patternLength);

	~PatternLengthIncHandler();

private:

	int& patternLength;

	void parameterChanged(const String& parameterID, float newValue) override;

};