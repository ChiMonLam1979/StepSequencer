#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "ChoiceUpdaterService.h"
#include "StepButtons.h"
#include "StepEncoders.h"

class SelectorButtonUpdaterService: public ChoiceUpdaterService
{
public:

	SelectorButtonUpdaterService
	(
		std::unique_ptr<StepButtons>& stepButtons,
		std::unique_ptr<StepButtons>& selectorButtons,
		std::unique_ptr<StepEncoders>&	stepEncoders
	);

	~SelectorButtonUpdaterService();

	void UpdateParameters(int value) override;

	void ShowGateButtons();
	void ShowEncoderSelectButtons();

	bool showingGateButtons { true };

private:

	std::unique_ptr<StepButtons>&	stepButtons;
	std::unique_ptr<StepButtons>&	selectorButtons;
	std::unique_ptr<StepEncoders>&	stepEncoders;
};