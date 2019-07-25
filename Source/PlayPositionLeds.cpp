#include "PlayPositionLeds.h"
#include "Parameters.h"

PlayPositionLeds::PlayPositionLeds(StepSequencerEngine& processor) : processor(processor)
{
	for (auto i = 0; i < 16; i++)
	{
		playPositionLedsOffArray.add(Drawable::createFromImageData(BinaryData::LEDOff_png, BinaryData::LEDOff_pngSize));
		playPositionLedsOnArray.add(Drawable::createFromImageData(BinaryData::LEDOn_png, BinaryData::LEDOn_pngSize));
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

	for (auto& led : playPositionLedsOnArray)
	{
		component.addAndMakeVisible(led);
		led->toFront(false);
		led->setVisible(false);
	}
}

void PlayPositionLeds::resized()
{
	auto firstLedXPos = ComponentPositions::PixelsFromLeftEdgeToFirstLED;
	auto spaceBetweenLeds = ComponentPositions::NumberOfPixelsBetweenLEDs;
	auto yPosOfLeds = ComponentPositions::YPositionOfLEDs;
	auto ledBounds = Rectangle<int>{ firstLedXPos, yPosOfLeds, ComponentSizes::LEDWidth, ComponentSizes::LEDHeight };

	for (auto i = 0; i < 16; i++)
	{
		auto led	= playPositionLedsOffArray.getUnchecked(i);
		auto ledOn	= playPositionLedsOnArray.getUnchecked(i);

		led->setBounds(ledBounds);
		ledOn->setBounds(ledBounds);

		ledBounds.setX(ledBounds.getX() + spaceBetweenLeds);
	}
}


void PlayPositionLeds::paint(Graphics& g)
{
	auto firstLedXPos = ComponentPositions::PixelsFromLeftEdgeToFirstLED;
	auto spaceBetweenLeds = ComponentPositions::NumberOfPixelsBetweenLEDs;
	auto yPosOfLeds = ComponentPositions::YPositionOfLEDs;
	auto ledBounds = Rectangle<int>{ firstLedXPos, yPosOfLeds, ComponentSizes::LEDWidth, ComponentSizes::LEDHeight };

	for (auto i = 0; i < 16; i++)
	{
		auto led	= playPositionLedsOffArray.getUnchecked(i);
		auto ledOn	= playPositionLedsOnArray.getUnchecked(i);

		PaintLed(g, led, ledBounds);
		PaintLed(g, ledOn, ledBounds);

		ledBounds.setX(ledBounds.getX() + spaceBetweenLeds);
	}
}

void PlayPositionLeds::PaintLed(Graphics& g, Drawable* led, Rectangle<int> bounds)
{
	led->setBounds(bounds);
	led->drawAt(g, 0, 0, 1);
}

void PlayPositionLeds::SetFlashingLedVisibility()
{
	shouldFlash	= processor.shouldFlash.load();
	ledIndex	= processor.playPositionIndex.load();

	if(shouldFlash)
	{
		auto ledToFlash			= playPositionLedsOnArray.getUnchecked(ledIndex);
		auto lastFlashingLed	= playPositionLedsOnArray.getUnchecked(lastLedIndex);
		auto OffledToShow		= playPositionLedsOffArray.getUnchecked(lastLedIndex);
		auto OffledToHide		= playPositionLedsOffArray.getUnchecked(ledIndex);

		if(lastLedIndex != ledIndex)
		{
			lastFlashingLed	->setVisible(false);
			OffledToShow	->setVisible(true);
			lastLedIndex	= ledIndex;
		}

		OffledToHide->setVisible(false);
		ledToFlash	->setVisible(true);
	}
	else
	{
		for (auto& led : playPositionLedsOffArray)
		{
			led->setVisible(true);
		}

		for (auto& led : playPositionLedsOnArray)
		{
			led->setVisible(false);
		}
	}
}