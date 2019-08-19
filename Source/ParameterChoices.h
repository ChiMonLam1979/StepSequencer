#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

namespace ParameterChoices
{
	const String Pitch		{ "Pitch"		};
	const String NoteLength	{ "Note Length" };
	const String Velocity	{ "Velocity"	};

	const StringArray StepChoices
	{
		Pitch,
		NoteLength,
		Velocity
	};

	const String stepButtonsSelect	{ "StepButtons Select"	};
	const String stepEncodersSelect	{ "StepEncoders Select"	};

	const StringArray stepSelectorChoices
	{
		stepButtonsSelect,
		stepEncodersSelect
	};
}