#include "StepEncoders.h"
#include "ComponentDimensions.h"
#include "ParameterNames.h"

StepEncoders::StepEncoders()
{
	for(auto i = 0; i < 16; i++)
	{
		encoderLeds.add(new LED);
		encoders.add(new Encoder(ParameterNames::StepEncoderNames[i], *encoderLeds[i], encoderLookAndFeel));
	}

	for(auto encoder: encoders)
	{
		addAndMakeVisible(encoder);
		encoder->onValueChange = [this, encoder] { encoderValueChanged(encoder->getName()); };
	}

	for(auto led : encoderLeds)
	{
		addAndMakeVisible(led);
		led->setState(Enums::LEDOff);
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

void StepEncoders::encoderValueChanged(const String& encoderName) const
{
	
}