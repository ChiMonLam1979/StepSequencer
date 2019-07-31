#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class NoteHandler : public AudioProcessorValueTreeState::Listener
{
public:

	NoteHandler();
	~NoteHandler();

private:

	void parameterChanged(const String& parameterID, float newValue) override;
};