#include "Parameters.h"
#include "StepSequencerEngine.h"
#include "ChaseLEDs.h"

ChaseLEDs::ChaseLEDs(StepSequencerEngine& processor) : processor(processor)
{
	for (auto i = 0; i < 16; i++)
	{
		leds.add(new ChaseLED);
	}

	for(auto led : leds)
	{
		addAndMakeVisible(led);
	}

	setInterceptsMouseClicks(false, true);

	startTimerHz(15);
}

ChaseLEDs::~ChaseLEDs()
{
}

void ChaseLEDs::resized()
{
	auto localBounds = getLocalBounds();
	auto spaceBetweenLeds = ComponentPositions::NumberOfPixelsBetweenChaseLEDs;
	auto bounds = Rectangle<int>{ localBounds.getX(), localBounds.getY(), ComponentSizes::LEDWidth, ComponentSizes::LEDHeight };

	for (auto i = 0; i < 16; i++)
	{
		leds[i]->setBounds(bounds);

		bounds.setX(bounds.getX() + spaceBetweenLeds);
	}
}

void ChaseLEDs::timerCallback()
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