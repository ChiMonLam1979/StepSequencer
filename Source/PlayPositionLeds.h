#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class PlayPositionLeds
{
public:

	PlayPositionLeds();
	~PlayPositionLeds();

	void MakeVisibleAndPaint(Graphics& g, Component& component);

	OwnedArray<Drawable>		playPositionLedsOffArray;
	std::unique_ptr<Drawable>	playPositionLedOn;

private:

	void PaintLed(Graphics& g, Drawable* led, Rectangle<int> bounds);
};