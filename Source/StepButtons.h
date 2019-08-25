#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepButton.h"

class StepButtons : public Component
{
public:

	StepButtons(Enums::StepButtonType buttonType, const StringArray& names, int numberOfButtons = 16);
	~StepButtons();

	void StepClicked(const String& stepButtonName) const;
	void CreateIncDecButtons(int numberOfButtons, const StringArray& names);
	void CreateMasterIncDecButtons(int numberOfButtons, const StringArray& names);
	void CreateButtons(int numberOfButtons, const StringArray& names, Enums::StepButtonType buttonType);

	std::vector<std::unique_ptr<StepButton>> stepButtons;

private:

};
