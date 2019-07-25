#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepButton.h"

class StepButtons
{
public:

	StepButtons();
	~StepButtons();

	void StepClicked(const String& stepButtonName) const;
	void MakeVisible(Component& component);

	OwnedArray<StepButton> stepButtons;

private:

};