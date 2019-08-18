#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "ChoiceUpdaterService.h"
#include "StepButtons.h"

class ButtonAttachmentUpdaterService: public ChoiceUpdaterService
{
public:

	ButtonAttachmentUpdaterService
	(
		OwnedArray<AudioProcessorValueTreeState::ButtonAttachment>& stepButtonAttachments,
		std::unique_ptr<StepButtons>&	stepButtons,
		AudioProcessorValueTreeState& treeState
	);
	~ButtonAttachmentUpdaterService();

	void UpdateParameters(String choice) override;

	void AttachButtonsToGates();
	void AttachButtonsToEncoderSelection();

private:

	OwnedArray<AudioProcessorValueTreeState::ButtonAttachment>&	stepButtonAttachments;
	std::unique_ptr<StepButtons>&								stepButtons;
	AudioProcessorValueTreeState&								treeState;
};
