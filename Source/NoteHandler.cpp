#include "NoteHandler.h"
#include "ParameterIds.h"
#include "ParameterDictionary.h"

NoteHandler::NoteHandler()
{
}

NoteHandler::~NoteHandler()
{
	
}

void NoteHandler::parameterChanged(const String& parameterID, float newValue)
{
	auto note	= static_cast<int>(newValue);
	auto index	= ParameterDictionaries::pitchDictionary[parameterID];

	notes[index] = note;
}