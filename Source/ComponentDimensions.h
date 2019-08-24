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

	const int IncButtonHeight				{ 30 };
	const int IncButtonWidth				{ 32 };

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
	const int YPositionOfEncoderLEDs				{ 345 };

	const int YPositionOfStepChoiceButtons			{ 270 };

	const int XPositionOfStepButtons				{ 110 };
	const int YPositionOfStepButtons				{ 385 };

	const float EncoderStartAngleRadians			{ 2.61779 };
	const float EncoderEndAngleRadians				{ 8.90118 };

	const int XPositionOfMasterEncoderLED			{ 22 };
	const int YPostionOfMasterEncoderLED			{ 345 };

	const int YPositionOfFirstIncDecButton			{ 355 };
	const int XPositionOfFirstIncDecButton			{ 110 };
	const int NumberOfPixelsBetweenIncDecButtons	{ 20 };
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

	const Rectangle<int> StepEncodersFirstLEDBounds
	{
		ComponentPositions::PixelsFromLeftEdgeToFirstEncoderLED,
		ComponentPositions::YPositionOfEncoderLEDs,
		ComponentSizes::LEDWidth,
		ComponentSizes::LEDHeight
	};

	const Rectangle<int> masterEncoderLEDBounds
	{
		ComponentPositions::XPositionOfMasterEncoderLED,
		ComponentPositions::YPostionOfMasterEncoderLED,
		ComponentSizes::LEDWidth,
		ComponentSizes::LEDHeight 
	};

	const Rectangle<int> StepEncodersFirstIncDecButtonsBounds
	{
		ComponentPositions::XPositionOfFirstIncDecButton,
		ComponentPositions::YPositionOfFirstIncDecButton - 200,
		ComponentSizes::IncButtonWidth * 32,
		ComponentSizes::IncButtonHeight
	};
}