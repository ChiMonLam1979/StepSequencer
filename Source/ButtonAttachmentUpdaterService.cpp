#include "ButtonAttachmentUpdaterService.h"
#include "ParameterChoices.h"
#include "ParameterIds.h"

ButtonAttachmentUpdaterService::ButtonAttachmentUpdaterService(
	OwnedArray<AudioProcessorValueTreeState::ButtonAttachment>& stepButtonAttachments,
	std::unique_ptr<StepButtons>& stepButtons,
	AudioProcessorValueTreeState& treeState)
	:
	stepButtonAttachments(stepButtonAttachments),
	stepButtons(stepButtons),
	treeState(treeState)
{
}

ButtonAttachmentUpdaterService::~ButtonAttachmentUpdaterService()
{
}

void ButtonAttachmentUpdaterService::UpdateParameters(String choice)
{
	if (choice == ParameterChoices::stepEncodersSelect)
	{
		AttachButtonsToEncoderSelection();
	}

	if (choice == ParameterChoices::stepButtonsSelect)
	{
		AttachButtonsToGates();
	}
}

void ButtonAttachmentUpdaterService::AttachButtonsToEncoderSelection()
{
	stepButtonAttachments.clear();

	for (auto i = 0; i < 16; i++)
	{
		stepButtonAttachments.add(new AudioProcessorValueTreeState::ButtonAttachment(treeState, IDs::SelectedEncoderIDs[i], *stepButtons->stepButtons[i]));
		stepButtons->stepButtons[i]->SetStepButtonStyle(Enums::Amber);
	}

	//for (auto button : stepButtons->stepButtons)
	//{
	//	button->SetStepButtonStyle(Enums::Amber);
	//}
}

void ButtonAttachmentUpdaterService::AttachButtonsToGates()
{
	stepButtonAttachments.clear();


	for (auto i = 0; i < 16; i++)
	{
		stepButtonAttachments.add(new AudioProcessorValueTreeState::ButtonAttachment(treeState, IDs::StepButtonIDs[i], *stepButtons->stepButtons[i]));
		stepButtons->stepButtons[i]->SetStepButtonStyle(Enums::Green);
	}

	//for(auto button: stepButtons->stepButtons)
	//{
	//	stepButtonAttachments.add(new AudioProcessorValueTreeState::ButtonAttachment(treeState, button->getName(), *button));
	//	button->SetStepButtonStyle(Enums::Green);
	//}
}