#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepButton.h"
#include "StepSequencerEngine.h"

class StepButtons : public Component
{
public:

	StepButtons(Enums::StepButtonType buttonType, const String& names, StepSequencerEngine& processor, const String& ID, int numberOfButtons = 16);

	~StepButtons();

	std::vector<std::unique_ptr<StepButton>> stepButtons;

private:

	void AttachToParameters(OwnedArray<AudioProcessorValueTreeState::ButtonAttachment>& attachments);
	void StepClicked(const String& stepButtonName) const;

	StepSequencerEngine& processor;

	int numberOfButtons { 0 };

	const String& ID;

	OwnedArray<AudioProcessorValueTreeState::ButtonAttachment> incAttachments{};
	OwnedArray<AudioProcessorValueTreeState::ButtonAttachment> decAttachments{};
	OwnedArray<AudioProcessorValueTreeState::ButtonAttachment> gateAttachments{};
	OwnedArray<AudioProcessorValueTreeState::ButtonAttachment> masterIncAttachments{};
	OwnedArray<AudioProcessorValueTreeState::ButtonAttachment> masterDecAttachments{};
	OwnedArray<AudioProcessorValueTreeState::ButtonAttachment> encoderSelectorAttachments{};
};
