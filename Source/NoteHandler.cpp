#include "NoteHandler.h"
#include "StepSequencerEngine.h"
#include "ParameterUtilities.h"

NoteHandler::NoteHandler(std::vector<int>& notes) : notes(notes)
{
}

NoteHandler::~NoteHandler()
{
	
}

void NoteHandler::parameterChanged(const String& parameterID, float newValue)
{
	auto note	= static_cast<int>(newValue);

	auto index = getParameterIndex(parameterID);

	notes[index] = note;
}