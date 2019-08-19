#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "ChoiceUpdaterService.h"
#include "StepButtons.h"
#include "StepEncoders.h"

class ButtonAttachmentUpdaterService: public ChoiceUpdaterService
{
public:

	ButtonAttachmentUpdaterService
	(
		std::unique_ptr<StepButtons>& stepButtons,
		std::unique_ptr<StepButtons>& selectorButtons,
		std::unique_ptr<StepEncoders>&	stepEncoders
	);

	~ButtonAttachmentUpdaterService();

	void UpdateParameters(String choice) override;

	void ShowGateButtons();
	void ShowEncoderSelectButtons();

	bool showingGateButtons { true };

private:

	std::unique_ptr<StepButtons>&	stepButtons;
	std::unique_ptr<StepButtons>&	selectorButtons;
	std::unique_ptr<StepEncoders>&	stepEncoders;
};