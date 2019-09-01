#include "StepButtons.h"
#include "ParameterNames.h"

StepButtons::StepButtons(Enums::StepButtonType buttonType, const String& name, StepSequencerEngine& processor, const String& ID, int numberOfButtons)
	: processor(processor), numberOfButtons(numberOfButtons), ID(ID)
{
	for (auto i = 0; i < numberOfButtons; i++)
	{
		auto number = String(i);
		auto button = std::make_unique<StepButton>((name + number), DrawableButton::ButtonStyle::ImageFitted, buttonType);
		stepButtons.push_back(std::move(button));
	}

	for (auto& stepButtonItem : stepButtons)
	{
		auto* stepButton = stepButtonItem.get();
		stepButton->onClick = [this, stepButton] { StepClicked(stepButton->getName()); };
		addAndMakeVisible(stepButton);
	}

	setInterceptsMouseClicks(false, true);

	switch(buttonType)
	{
	case Enums::IncButton: AttachToParameters(incAttachments);
		break;
	case Enums::DecButton: AttachToParameters(decAttachments);
		break;
	case Enums::GateButton: AttachToParameters(gateAttachments);
		break;
	case Enums::MasterIncButton: AttachToParameters(masterIncAttachments);
		break;
	case Enums::MasterDecButton: AttachToParameters(masterDecAttachments);
		break;
	case Enums::EncoderSelectorButton: AttachToParameters(encoderSelectorAttachments);
		break;
	default: break;
	}
}

StepButtons::~StepButtons()
{
}

void StepButtons::AttachToParameters(OwnedArray<AudioProcessorValueTreeState::ButtonAttachment>& attachments)
{
	for (auto i = 0; i < numberOfButtons; ++i)
	{
		auto number = String(i);
		attachments.add(new AudioProcessorValueTreeState::ButtonAttachment(processor.treeState, ID + number, *this->stepButtons[i]));
	}
}

void StepButtons::StepClicked(const String& stepButtonName) const
{
}