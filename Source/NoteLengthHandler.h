#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "NoteHandler.h"

class NoteLengthHandler : public AudioProcessorValueTreeState::Listener
{
public:

	NoteLengthHandler(std::vector<int>& noteLengths, double& samplesPerNoteDivision);

	~NoteLengthHandler();

	std::vector<int>& noteLengths;

	double& samplesPerNoteDivision;

private:

	void parameterChanged(const String& parameterID, float newValue) override;

	const String& genericParameterID{ IDs::NoteLengthEncoderID };

};