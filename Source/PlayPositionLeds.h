#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepSequencerEngine.h"

class PlayPositionLeds : public Component
{
public:

	PlayPositionLeds(StepSequencerEngine& processor);
	~PlayPositionLeds();

	void MakeVisible(Component& component);

	void paint(Graphics& g) override;

	void resized() override;

	void SetFlashingLedVisibility();

	OwnedArray<Drawable>		playPositionLedsOffArray;
	OwnedArray<Drawable>		playPositionLedsOnArray;

	std::unique_ptr<Drawable>	playPositionLedOn;

	bool shouldFlash	{ false };
	int	 lastLedIndex	{ 0 };
	int	 ledIndex		{ 0 };

	StepSequencerEngine& processor;

private:

	void PaintLed(Graphics& g, Drawable* led, Rectangle<int> bounds);
};