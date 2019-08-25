#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class SelectAllButtonHandler : public AudioProcessorValueTreeState::Listener
{
public:

	SelectAllButtonHandler();
	~SelectAllButtonHandler();

private:

	void parameterChanged(const String& parameterID, float newValue) override;

};