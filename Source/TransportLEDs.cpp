#include "TransportLEDs.h"
#include "Parameters.h"

TransportLEDs::TransportLEDs(StepSequencerEngine& processor) : processor(processor)
{
	for (auto i = 0; i < 16; i++)
	{
		onLeds .add(new PNG(ImageCache::getFromMemory(BinaryData::LEDOn_png, BinaryData::LEDOn_pngSize)));
		offLeds.add(new PNG(ImageCache::getFromMemory(BinaryData::LEDOff_png, BinaryData::LEDOff_pngSize)));
	}

	for(auto png : onLeds)
	{
		addAndMakeVisible(png);
	}

	for(auto png : offLeds)
	{
		addAndMakeVisible(png);
	}
}

TransportLEDs::~TransportLEDs()
{
}

void TransportLEDs::resized()
{
	auto firstXPosition		= ComponentPositions::PixelsFromLeftEdgeToFirstLED;
	auto spaceBetweenLeds	= ComponentPositions::NumberOfPixelsBetweenLEDs;
	auto yPosition			= ComponentPositions::YPositionOfLEDs;
	auto bounds				= Rectangle<int>{ firstXPosition, yPosition, ComponentSizes::LEDWidth, ComponentSizes::LEDHeight };

	for (auto i = 0; i < 16; i++)
	{
		auto led	= onLeds[i];
		auto ledOn	= offLeds[i];

		led	 ->setBounds(bounds);
		ledOn->setBounds(bounds);

		bounds.setX(bounds.getX() + spaceBetweenLeds);
	}
}

void TransportLEDs::UpdateFlashingLED()
{
	shouldFlash = processor.shouldFlash.load();
	index		= processor.playPositionIndex.load();

	if (shouldFlash)
	{
		auto ledToFlash			= onLeds[index];
		auto lastFlashingLed	= onLeds[lastIndex];
		auto OffledToShow		= offLeds[lastIndex];
		auto OffledToHide		= offLeds[index];

		if (lastIndex != index)
		{
			lastFlashingLed->setVisible(false);
			OffledToShow->setVisible(true);
			lastIndex = index;
		}

		OffledToHide->setVisible(false);
		ledToFlash->setVisible(true);
	}
	else
	{
		for (auto& led : offLeds)
		{
			led->setVisible(true);
		}

		for (auto& led : onLeds)
		{
			led->setVisible(false);
		}
	}
}