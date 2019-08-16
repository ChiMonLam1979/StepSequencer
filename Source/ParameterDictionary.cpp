#include "ParameterDictionary.h"
#include "ParameterIds.h"

const std::map<String, int> pitchDictionary
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

const std::map<String, int> noteLengthDictionary
{
	{ IDs::NoteLengthEncoderOneID,			0	},
	{ IDs::NoteLengthEncoderTwoID,			1	},
	{ IDs::NoteLengthEncoderThreeID,		2	},
	{ IDs::NoteLengthEncoderFourID,			3	},
	{ IDs::NoteLengthEncoderFiveID,			4	},
	{ IDs::NoteLengthEncoderSixID,			5	},
	{ IDs::NoteLengthEncoderSevenID,		6	},
	{ IDs::NoteLengthEncoderEightID,		7	},
	{ IDs::NoteLengthEncoderNineID,			8	},
	{ IDs::NoteLengthEncoderTenID,			9	},
	{ IDs::NoteLengthEncoderElevenID,		10	},
	{ IDs::NoteLengthEncoderTwelveID,		11	},
	{ IDs::NoteLengthEncoderThirteenID,		12	},
	{ IDs::NoteLengthEncoderFourteenID,		13	},
	{ IDs::NoteLengthEncoderFifteenID,		14	},
	{ IDs::NoteLengthEncoderSixteenID,		15	}
};

const std::map<String, int> velocityDictionary
{
	{ IDs::VelocityEncoderOneID,			0	},
	{ IDs::VelocityEncoderTwoID,			1	},
	{ IDs::VelocityEncoderThreeID,			2	},
	{ IDs::VelocityEncoderFourID,			3	},
	{ IDs::VelocityEncoderFiveID,			4	},
	{ IDs::VelocityEncoderSixID,			5	},
	{ IDs::VelocityEncoderSevenID,			6	},
	{ IDs::VelocityEncoderEightID,			7	},
	{ IDs::VelocityEncoderNineID,			8	},
	{ IDs::VelocityEncoderTenID,			9	},
	{ IDs::VelocityEncoderElevenID,			10	},
	{ IDs::VelocityEncoderTwelveID,			11	},
	{ IDs::VelocityEncoderThirteenID,		12	},
	{ IDs::VelocityEncoderFourteenID,		13	},
	{ IDs::VelocityEncoderFifteenID,		14	},
	{ IDs::VelocityEncoderSixteenID,		15	}
};

const std::map<String, int> gateDictionary
{
	{ IDs::StepButtonOneID,				0	},
	{ IDs::StepButtonTwoID,				1	},
	{ IDs::StepButtonThreeID,			2	},
	{ IDs::StepButtonFourID,			3	},
	{ IDs::StepButtonFiveID,			4	},
	{ IDs::StepButtonSixID,				5	},
	{ IDs::StepButtonSevenID,			6	},
	{ IDs::StepButtonEightID,			7	},
	{ IDs::StepButtonNineID,			8	},
	{ IDs::StepButtonTenID,				9	},
	{ IDs::StepButtonElevenID,			10	},
	{ IDs::StepButtonTwelveID,			11	},
	{ IDs::StepButtonThirteenID,		12	},
	{ IDs::StepButtonFourteenID,		13	},
	{ IDs::StepButtonFifteenID,			14	},
	{ IDs::StepButtonSixteenID,			15	}
};

Image getLedImage(Enums::LEDState state)
{
	static const std::map<Enums::LEDState, juce::Image> ledDictionary
	{
		{ Enums::LEDState::LEDOff,		ImageCache::getFromMemory(BinaryData::LEDOff_png, BinaryData::LEDOff_pngSize) },
		{ Enums::LEDState::LEDGreen,	ImageCache::getFromMemory(BinaryData::LEDOnGreen_png, BinaryData::LEDOnGreen_pngSize) },
		{ Enums::LEDState::LEDRed,		ImageCache::getFromMemory(BinaryData::LEDOnRed_png, BinaryData::LEDOnRed_pngSize) }
	};

	const auto it = ledDictionary.find(state);
	return it != ledDictionary.cend() ? it->second : Image{};
}