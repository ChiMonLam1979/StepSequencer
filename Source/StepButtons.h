#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepButton.h"

class StepButtons : public Component
{
public:

	StepButtons();
	~StepButtons();

	void StepClicked(const String& stepButtonName) const;

	std::vector<std::unique_ptr<StepButton>> stepButtons;


private:

};