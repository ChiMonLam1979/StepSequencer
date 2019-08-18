#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

namespace ParameterChoices
{
	static String Pitch		{ "Pitch"		};
	static String NoteLength{ "Note Length" };
	static String Velocity	{ "Velocity"	};

	const StringArray StepChoices
	{
		Pitch,
		NoteLength,
		Velocity
	};

	static String stepButtonsSelect	{ "StepButtons Select"	};
	static String stepEncodersSelect{ "StepEncoders Select"	};

	const StringArray stepSelectorChoices
	{
		stepButtonsSelect,
		stepEncodersSelect
	};
}