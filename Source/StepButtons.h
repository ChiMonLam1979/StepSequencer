#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepButton.h"

class StepButtons : public Component
{
public:

	StepButtons();
	~StepButtons();

	void StepClicked(const String& stepButtonName) const;

	OwnedArray<StepButton> stepButtons;

private:

};