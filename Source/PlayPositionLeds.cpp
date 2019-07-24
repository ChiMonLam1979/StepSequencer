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

void PlayPositionLeds::MakeVisibleAndPaint(Graphics& g, Component& component)
{
	auto firstLedXPos		= ComponentPositions::PixelsFromLeftEdgeToFirstLED;
	auto spaceBetweenLeds	= ComponentPositions::NumberOfPixelsBetweenLEDs;
	auto yPosOfLeds			= ComponentPositions::YPositionOfLEDs;
	auto ledBounds			= Rectangle<int>{ firstLedXPos, yPosOfLeds, ComponentSizes::LEDWidth, ComponentSizes::LEDHeight };
	auto ledShouldFlash		= true;
	auto indexOfFlashingLed = 12;
	auto ledOn				= playPositionLedOn.get();

	for (auto i = 0; i < 16; i++)
	{
		if (i == indexOfFlashingLed && ledShouldFlash)
		{
			component.addAndMakeVisible(ledOn);
			PaintLed(g, ledOn, ledBounds);
		}
		else
		{
			auto led = playPositionLedsOffArray.getUnchecked(i);

			component.addAndMakeVisible(led);
			PaintLed(g, led, ledBounds);
		}

		ledBounds.setX(ledBounds.getX() + spaceBetweenLeds);
	}
}

void PlayPositionLeds::PaintLed(Graphics& g, Drawable* led, Rectangle<int> bounds)
{
	led->setBounds(bounds);
	led->drawAt(g, 0, 0, 1);
	led->toFront(false);
}