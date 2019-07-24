#include "PlayPositionLeds.h"
#include "Parameters.h"

PlayPositionLeds::PlayPositionLeds()
{
	playPositionLedOn = Drawable::createFromImageData(BinaryData::LEDOn_png, BinaryData::LEDOn_pngSize);

	for (auto i = 0; i < 16; i++)
	{
		playPositionLedsOffArray.add(Drawable::createFromImageData(BinaryData::LEDOff_png, BinaryData::LEDOff_pngSize));
	}
}

PlayPositionLeds::~PlayPositionLeds()
{
}

void PlayPositionLeds::paintLeds(Graphics& g)
{
	auto firstLedXPos		= ComponentPositions::PixelsFromLeftEdgeToFirstLED;
	auto spaceBetweenLeds	= ComponentPositions::NumberOfPixelsBetweenLEDs;
	auto yPosOfLeds			= ComponentPositions::YPositionOfLEDs;
	auto ledBounds			= Rectangle<int>{ firstLedXPos, yPosOfLeds, ComponentSizes::LEDWidth, ComponentSizes::LEDHeight };
	auto ledShouldFlash		= true;
	auto indexOfFlashingLed = 12;

	for (auto i = 0; i < 16; i++)
	{
		auto led = playPositionLedsOffArray.getUnchecked(i);

		if (i == indexOfFlashingLed && ledShouldFlash)
		{
			paintLed(g, playPositionLedOn.get(), ledBounds);
		}
		else
		{
			paintLed(g, led, ledBounds);
		}

		ledBounds.setX(ledBounds.getX() + spaceBetweenLeds);
	}
}

void PlayPositionLeds::paintLed(Graphics& g, Drawable* led, Rectangle<int> bounds)
{
	addAndMakeVisible(led);
	led->setBounds(bounds);
	led->drawAt(g, 0, 0, 1);
	led->toFront(false);
}