#include "Parameters.h"
#include "StepEncoders.h"

StepEncoders::StepEncoders()
{
	for(auto i = 0; i < 16; i++)
	{
		encoderLeds.add(new EncoderLED);
		encoders.add(new Encoder(ParameterNames::StepEncoderNames[i], *encoderLeds[i]));
	}

	for(auto encoder: encoders)
	{
		addAndMakeVisible(encoder);
	}

	for(auto led : encoderLeds)
	{
		addAndMakeVisible(led);
	}

	setInterceptsMouseClicks(false, true);
}

StepEncoders::~StepEncoders()
{
	
}

void StepEncoders::resized()
{
	auto spaceBetweenLeds = ComponentPositions::NumberOfPixelsBetweenEncoderLEDs;
	auto bounds = Rectangle<int>
	{
		ComponentPositions::PixelsFromLeftEdgeToFirstEncoderLED,
		ComponentPositions::YPositionOfEncoderLEDs,
		ComponentSizes::LEDWidth,
		ComponentSizes::LEDHeight };

	for (auto i = 0; i < 16; i++)
	{
		encoderLeds[i]->setBounds(bounds);

		bounds.setX(bounds.getX() + spaceBetweenLeds);
	}
}