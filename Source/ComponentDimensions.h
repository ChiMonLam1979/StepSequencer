#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

namespace ComponentSizes
{
	static int windowHeight{ 500 };
	static int windowWidth{ 1260 };

	static int StepButtonHeight{ 65 };
	static int StepButtonWidth{ 65 };

	static int StepEncoderHeight{ 65 };
	static int StepEncoderWidth{ 65 };

	static int UnderStepButtonsPanelHeight{ 50 };
	static int LEDHeight{ 17 };
	static int LEDWidth{ 17 };

	static int blankSidePanelWidth{ 110 };
}

namespace ComponentPositions
{
	static int PixelsFromLeftEdgeToFirstChaseLED{ 158 };
	static int NumberOfPixelsBetweenChaseLEDs{ 65 };
	static int YPositionOfChaseLEDs{ 450 };

	static int PixelsFromLeftEdgeToFirstEncoderLED{ 112 };
	static int NumberOfPixelsBetweenEncoderLEDs{ 65 };
	static int YPositionOfEncoderLEDs{ 370 };

	static int YPositionOfStepChoiceButtons{ 270 };
}

namespace ComponentBounds
{
	static Rectangle<int> ChaseLEDStripBounds
	{
		ComponentPositions::PixelsFromLeftEdgeToFirstChaseLED,
		ComponentPositions::YPositionOfChaseLEDs,
		ComponentSizes::windowWidth,
		ComponentSizes::LEDHeight
	};
}