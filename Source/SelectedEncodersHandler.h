#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class SelectedEncodersHandler : public AudioProcessorValueTreeState::Listener
{
public:

	SelectedEncodersHandler();
	~SelectedEncodersHandler();

private:

	void parameterChanged(const String& parameterID, float newValue) override;

};