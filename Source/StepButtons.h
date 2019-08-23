#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepButton.h"

class StepButtons : public Component
{
public:

	StepButtons(Enums::StepButtonType buttonType, const StringArray& names, int numberOfButtons = 16);
	~StepButtons();

	void StepClicked(const String& stepButtonName) const;

	std::vector<std::unique_ptr<StepButton>> stepButtons;

private:

};