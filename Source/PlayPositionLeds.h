#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class PlayPositionLeds : public Component
{
public:

	PlayPositionLeds();
	~PlayPositionLeds();

	void paintLeds(Graphics& g);

	OwnedArray<Drawable>		playPositionLedsOffArray;
	std::unique_ptr<Drawable>	playPositionLedOn;

private:

	void paintLed(Graphics& g, Drawable* led, Rectangle<int> bounds);
};