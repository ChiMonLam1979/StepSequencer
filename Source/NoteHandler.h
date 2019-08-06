#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class NoteHandler : public AudioProcessorValueTreeState::Listener
{
public:

	NoteHandler();
	~NoteHandler();

	std::vector<int> notes = std::vector<int>(16);

private:

	void parameterChanged(const String& parameterID, float newValue) override;
};