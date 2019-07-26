#include "TransportLEDs.h"
#include "Parameters.h"

TransportLEDs::TransportLEDs(StepSequencerEngine& processor) : processor(processor)
{
	for (auto i = 0; i < 16; i++)
	{
		leds.add(new LED);
	}

	for(auto led : leds)
	{
		addAndMakeVisible(led);
	}

	setInterceptsMouseClicks(false, true);
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
		leds[i]->setBounds(bounds);

		bounds.setX(bounds.getX() + spaceBetweenLeds);
	}
}

void TransportLEDs::UpdateFlashingLED()
{
	shouldFlash = processor.shouldFlash.load();
	index		= processor.playPositionIndex.load();

	if(shouldFlash)
	{
		leds[index]->toggle(true);
	}

	if(lastIndex != index)
	{
		leds[lastIndex]->toggle(false);
		lastIndex = index;
	}

	if(!shouldFlash)
	{
		for (auto led : leds)
		{
		led->toggle(false);
		}
	}
}