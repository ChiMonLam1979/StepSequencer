#include "StepEncoders.h"
#include "ComponentDimensions.h"
#include "ParameterNames.h"

StepEncoders::StepEncoders(std::unique_ptr<GroupEncoder>& groupEncoder)
{
	for(auto i = 0; i < 16; i++)
	{
		auto led = std::make_unique<LED>();
		encoderLeds.push_back(std::move(led));

		auto encoder = std::make_unique<Encoder>(ParameterNames::StepEncoderNames[i], *encoderLeds[i], groupEncoder);
		encoders.push_back(std::move(encoder));
	}

	for(auto& encoderItem: encoders)
	{
		auto* encoder = encoderItem.get();

		addAndMakeVisible(encoder);
		encoder->onValueChange = [this, encoder] { encoderValueChanged(encoder->getName()); };
	}

	for(auto& ledItem : encoderLeds)
	{
		addAndMakeVisible(ledItem.get());
		ledItem->setState(Enums::LEDOff);
	}

	setInterceptsMouseClicks(false, true);
}

StepEncoders::~StepEncoders()
{
	
}

void StepEncoders::resized()
{
	auto spaceBetweenLeds = ComponentPositions::NumberOfPixelsBetweenEncoderLEDs;
	Rectangle<int> bounds
	(
		ComponentPositions::PixelsFromLeftEdgeToFirstEncoderLED,
		ComponentPositions::YPositionOfEncoderLEDs,
		ComponentSizes::LEDWidth,
		ComponentSizes::LEDHeight );

	for (auto i = 0; i < 16; i++)
	{
		encoderLeds[i]->setBounds(bounds);

		bounds.setX(bounds.getX() + spaceBetweenLeds);
	}
}

void StepEncoders::encoderValueChanged(const String& encoderName) const
{
	
}