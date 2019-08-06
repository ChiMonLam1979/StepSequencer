#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "ParameterIds.h"

namespace ParameterDictionaries
{
	static std::map<String, int> pitchDictionary
	{
		{ IDs::PitchEncoderOneID,			0	},
		{ IDs::PitchEncoderTwoID,			1	},	
		{ IDs::PitchEncoderThreeID,			2	},
		{ IDs::PitchEncoderFourID,			3	},
		{ IDs::PitchEncoderFiveID,			4	},
		{ IDs::PitchEncoderSixID,			5	},
		{ IDs::PitchEncoderSevenID,			6	},
		{ IDs::PitchEncoderEightID,			7	},
		{ IDs::PitchEncoderNineID,			8	},
		{ IDs::PitchEncoderTenID,			9	},
		{ IDs::PitchEncoderElevenID,		10	},
		{ IDs::PitchEncoderTwelveID,		11	},
		{ IDs::PitchEncoderThirteenID,		12	},
		{ IDs::PitchEncoderFourteenID,		13	},
		{ IDs::PitchEncoderFifteenID,		14	},
		{ IDs::PitchEncoderSixteenID,		15	}
	};
}