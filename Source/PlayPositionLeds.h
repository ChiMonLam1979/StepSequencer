#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class PlayPositionLeds
{
public:

	PlayPositionLeds();
	~PlayPositionLeds();

	void MakeVisible(Component& component);
	void Paint(Graphics& g);

	OwnedArray<Drawable>		playPositionLedsOffArray;
	std::unique_ptr<Drawable>	playPositionLedOn;

private:

	void PaintLed(Graphics& g, Drawable* led, Rectangle<int> bounds);
};