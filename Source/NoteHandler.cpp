#include "NoteHandler.h"
#include "ParameterDictionary.h"
#include "StepSequencerEngine.h"

NoteHandler::NoteHandler(std::vector<int>& notes) : notes(notes)
{
}

NoteHandler::~NoteHandler()
{
	
}

void NoteHandler::parameterChanged(const String& parameterID, float newValue)
{
	auto note	= static_cast<int>(newValue);
	auto index = getParameterIndex(genericParameterID, parameterID, DefaultValues::NumberOfSteps);

	notes[index] = note;
}