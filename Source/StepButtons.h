#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepButton.h"
#include "StepSequencerEngine.h"

class StepButtons : public Component
{
public:

	StepButtons(Enums::StepButtonType buttonType, const String& names, StepSequencerEngine& processor, int numberOfButtons = 16);

	~StepButtons();

	void StepClicked(const String& stepButtonName) const;

	void AttachToParameters(OwnedArray<AudioProcessorValueTreeState::ButtonAttachment>& attachments);

	std::vector<std::unique_ptr<StepButton>> stepButtons;

private:

	StepSequencerEngine& processor;

	int numberOfButtons { 0 };
	const String& name;

	OwnedArray<AudioProcessorValueTreeState::ButtonAttachment> incAttachments{};
	OwnedArray<AudioProcessorValueTreeState::ButtonAttachment> decAttachments{};
	OwnedArray<AudioProcessorValueTreeState::ButtonAttachment> gateAttachments{};
	OwnedArray<AudioProcessorValueTreeState::ButtonAttachment> masterIncAttachments{};
	OwnedArray<AudioProcessorValueTreeState::ButtonAttachment> masterDecAttachments{};
	OwnedArray<AudioProcessorValueTreeState::ButtonAttachment> encoderSelectorAttachments{};
};
