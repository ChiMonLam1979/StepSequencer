#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

namespace ParameterChoices
{
	static String Pitch{ "Pitch" };
	static String NoteLength{ "Note Length" };
	static String Velocity{ "Velocity" };

	const StringArray StepChoices
	{
		Pitch,
		NoteLength,
		Velocity
	};
}