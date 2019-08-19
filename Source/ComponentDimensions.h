#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

namespace ComponentSizes
{
	const int windowHeight					{ 500 };
	const int windowWidth					{ 1260 };

	const int StepButtonHeight				{ 65 };
	const int StepButtonWidth				{ 65 };

	const int StepEncoderHeight				{ 65 };
	const int StepEncoderWidth				{ 65 };

	const int UnderStepButtonsPanelHeight	{ 50 };
	const int LEDHeight						{ 17 };
	const int LEDWidth						{ 17 };

	const int blankSidePanelWidth			{ 110 };
}

namespace ComponentPositions
{
	const int PixelsFromLeftEdgeToFirstChaseLED		{ 158 };
	const int NumberOfPixelsBetweenChaseLEDs		{ 65 };
	const int YPositionOfChaseLEDs					{ 450 };

	const int PixelsFromLeftEdgeToFirstEncoderLED	{ 112 };
	const int NumberOfPixelsBetweenEncoderLEDs		{ 65 };
	const int YPositionOfEncoderLEDs				{ 370 };

	const int YPositionOfStepChoiceButtons			{ 270 };

	const int XPositionOfStepButtons				{ 110 };
	const int YPositionOfStepButtons				{ 385 };
}

namespace ComponentBounds
{
	const Rectangle<int> ChaseLEDStripBounds
	{
		ComponentPositions::PixelsFromLeftEdgeToFirstChaseLED,
		ComponentPositions::YPositionOfChaseLEDs,
		ComponentSizes::windowWidth,
		ComponentSizes::LEDHeight
	};

	const Rectangle<int> StepButtonBounds
	{
		ComponentPositions::XPositionOfStepButtons,
		ComponentPositions::YPositionOfStepButtons,
		ComponentSizes::StepButtonWidth * 16,
		ComponentSizes::StepButtonHeight
	};
}