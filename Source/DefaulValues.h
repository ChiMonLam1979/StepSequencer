#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

namespace DefaultValues
{
	const int		Pitch				{ 36	};
	const uint8		Velocity			{ 100	};
	const double	NoteLengthValue		{ 63	};
	const double	NoteLength			{ 2756	};
	const int		MidiUppperRangeValue{ 127	};
	const bool		Gate				{ false };
	const bool		EncoderSelectState	{ false };

	const int		NumberOfSteps		{ 16	};

	const StringRef	ParameterDelimiter	{ ":"	};
	const StringRef QuoteCharacters     { ""	};
}