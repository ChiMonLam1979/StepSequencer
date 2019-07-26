#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

namespace  ParameterNames
{
	static String StepButtonOneName		{ "Step Button One"			};
	static String StepButtonTwoName		{ "Step Button Two"			};
	static String StepButtonThreeName	{ "Step Button Three"		};
	static String StepButtonFourName	{ "Step Button Four"		};
	static String StepButtonFiveName	{ "Step Button Five"		};
	static String StepButtonSixName		{ "Step Button Six"			};
	static String StepButtonSevenName	{ "Step Button Seven"		};
	static String StepButtonEightName	{ "Step Button Eight"		};
	static String StepButtonNineName	{ "Step Button Nine"		};
	static String StepButtonTenName		{ "Step Button Ten"			};
	static String StepButtonElevenName	{ "Step Button Eleven"		};
	static String StepButtonTwelveName	{ "Step Button Twelve"		};
	static String StepButtonThirteenName{ "Step Button Thirteen"	};
	static String StepButtonFourteenName{ "Step Button Fourteen"	};
	static String StepButtonFifteenName	{ "Step Button Fifteen"		};
	static String StepButtonSixteenName	{ "Step Button Sixteen"		};

	const StringArray StepButtonNames
	{
		StepButtonOneName,
		StepButtonTwoName,
		StepButtonThreeName,
		StepButtonFourName,
		StepButtonFiveName,
		StepButtonSixName,
		StepButtonSevenName,
		StepButtonEightName,
		StepButtonNineName,
		StepButtonTenName,
		StepButtonElevenName,
		StepButtonTwelveName,
		StepButtonThirteenName,
		StepButtonFourteenName,
		StepButtonFifteenName,
		StepButtonSixteenName,
	};

	static String StepEncoderOneName		{ "Step Encoder One"		};
	static String StepEncoderTwoName		{ "Step Encoder Two"		};
	static String StepEncoderThreeName		{ "Step Encoder Three"		};
	static String StepEncoderFourName		{ "Step Encoder Four"		};
	static String StepEncoderFiveName		{ "Step Encoder Five"		};
	static String StepEncoderSixName		{ "Step Encoder Six"		};
	static String StepEncoderSevenName		{ "Step Encoder Seven"		};
	static String StepEncoderEightName		{ "Step Encoder Eight"		};
	static String StepEncoderNineName		{ "Step Encoder Nine"		};
	static String StepEncoderTenName		{ "Step Encoder Ten"		};
	static String StepEncoderElevenName		{ "Step Encoder Eleven"		};
	static String StepEncoderTwelveName		{ "Step Encoder Twelve"		};
	static String StepEncoderThirteenName	{ "Step Encoder Thirteen"	};
	static String StepEncoderFourteenName	{ "Step Encoder Fourteen"	};
	static String StepEncoderFifteenName	{ "Step Encoder Fifteen"	};
	static String StepEncoderSixteenName	{ "Step Encoder Sixteen"	};

	const StringArray StepEncoderNames
	{
		StepEncoderOneName,
		StepEncoderTwoName,
		StepEncoderThreeName,
		StepEncoderFourName,
		StepEncoderFiveName,
		StepEncoderSixName,
		StepEncoderSevenName,
		StepEncoderEightName,
		StepEncoderNineName,
		StepEncoderTenName,
		StepEncoderElevenName,
		StepEncoderTwelveName,
		StepEncoderThirteenName,
		StepEncoderFourteenName,
		StepEncoderFifteenName,
		StepEncoderSixteenName
	};
}

namespace ComponentSizes
{
	static int windowHeight					{ 500 };
	static int windowWidth					{ 1140 };

	static int StepButtonHeight				{ 65 };
	static int StepButtonWidth				{ 65 };

	static int StepEncoderHeight			{ 65 };
	static int StepEncoderWidth				{ 65 };

	static int UnderStepButtonsPanelHeight	{ 50 };
	static int LEDHeight					{ 17 };
	static int LEDWidth						{ 17 };
}

namespace ComponentPositions
{
	static int PixelsFromLeftEdgeToFirstLED	{ 98 };
	static int NumberOfPixelsBetweenLEDs	{ 65 };
	static int YPositionOfLEDs				{ 450 };
}

namespace ComponentBounds
{
	static Rectangle<int> TransportLEDStripBounds
	{
		ComponentPositions::PixelsFromLeftEdgeToFirstLED,
		ComponentPositions::YPositionOfLEDs,
		ComponentSizes::windowWidth,
		ComponentSizes::LEDHeight
	};
}

namespace ProjectColours
{
	static Colour backGround = Colour(200, 201, 187);
}