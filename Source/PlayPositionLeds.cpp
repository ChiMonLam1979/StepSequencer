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

void PlayPositionLeds::MakeVisible(Component& component)
{
	for(auto& led : playPositionLedsOffArray)
	{
		component.addAndMakeVisible(led);
		led->toFront(false);
	}

	component.addAndMakeVisible(playPositionLedOn.get());
	playPositionLedOn.get()->toFront(false);
}


void PlayPositionLeds::Paint(Graphics& g)
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
			PaintLed(g, ledOn, ledBounds);
		}
		else
		{
			auto led = playPositionLedsOffArray.getUnchecked(i);

			PaintLed(g, led, ledBounds);
		}
		if(!ledShouldFlash)
		{
			ledOn->toBack();
		}

		ledBounds.setX(ledBounds.getX() + spaceBetweenLeds);
	}
}

void PlayPositionLeds::PaintLed(Graphics& g, Drawable* led, Rectangle<int> bounds)
{
	led->setBounds(bounds);
	led->drawAt(g, 0, 0, 1);
}