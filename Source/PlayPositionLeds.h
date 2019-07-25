#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepSequencerEngine.h"

class PlayPositionLeds
{
public:

	PlayPositionLeds(StepSequencerEngine& processor);
	~PlayPositionLeds();

	void MakeVisible(Component& component);

	void Paint(Graphics& g);

	void SetFlashingLedVisibility();

	OwnedArray<Drawable>		playPositionLedsOffArray;
	OwnedArray<Drawable>		playPositionLedsOnArray;

	bool shouldFlash	{ false };
	int	 lastLedIndex	{ 0 };
	int	 ledIndex		{ 0 };

	StepSequencerEngine& processor;

private:

	void PaintLed(Graphics& g, Drawable* led, Rectangle<int> bounds);
};