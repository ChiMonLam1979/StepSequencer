#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class GroupEncoderHandler : public AudioProcessorValueTreeState::Listener
{
public:

	GroupEncoderHandler();
	~GroupEncoderHandler();	

private:

	void parameterChanged(const String& parameterID, float newValue) override;
};