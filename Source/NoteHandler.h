#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "ParameterIds.h"

class NoteHandler : public AudioProcessorValueTreeState::Listener
{
public:

	NoteHandler(std::vector<int>& notes);

	~NoteHandler();

	std::vector<int>& notes;

private:

	void parameterChanged(const String& parameterID, float newValue) override;

	const String& genericParameterID{ IDs::PitchEncoderID };
};
