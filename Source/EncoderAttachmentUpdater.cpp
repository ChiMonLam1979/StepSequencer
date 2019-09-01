#include "EncoderAttachmentUpdater.h"
#include "ParameterChoices.h"
#include "ParameterIds.h"

EncoderAttachmentUpdater::EncoderAttachmentUpdater
(
	OwnedArray<AudioProcessorValueTreeState::SliderAttachment>& stepEncoderAttachments,
	std::vector<std::unique_ptr<Encoder>>&	encoders,
	AudioProcessorValueTreeState& treeState
)
	:
	stepEncoderAttachments(stepEncoderAttachments),
	encoders(encoders),
	treeState(treeState)
{	
}

EncoderAttachmentUpdater::~EncoderAttachmentUpdater()
{
	
}

void EncoderAttachmentUpdater::UpdateParameters(int value)
{
	const auto choice = ParameterChoices::StepChoices[value];

	if (choice == ParameterChoices::Pitch)
	{
		AttachEncodersToPitch();
	}

	if (choice == ParameterChoices::NoteLength)
	{
		AttachEncodersToNoteLength();
	}

	if (choice == ParameterChoices::Velocity)
	{
		AttachEncodersToVelocity();
	}
}

void EncoderAttachmentUpdater::AttachEncodersToPitch()
{
	stepEncoderAttachments.clear();

	for (auto i = 0; i < 16; i++)
	{
		auto number = String(i);
		stepEncoderAttachments.add(new AudioProcessorValueTreeState::SliderAttachment(treeState, IDs::PitchEncoderID + number, *encoders[i]));
	}
}

void EncoderAttachmentUpdater::AttachEncodersToNoteLength()
{
	stepEncoderAttachments.clear();

	for (auto i = 0; i < 16; i++)
	{
		auto number = String(i);
		stepEncoderAttachments.add(new AudioProcessorValueTreeState::SliderAttachment(treeState, IDs::NoteLengthEncoderID + number, *encoders[i]));
	}
}

void EncoderAttachmentUpdater::AttachEncodersToVelocity()
{
	stepEncoderAttachments.clear();

	for (auto i = 0; i < 16; i++)
	{
		auto number = String(i);
		stepEncoderAttachments.add(new AudioProcessorValueTreeState::SliderAttachment(treeState, IDs::VelocityEncoderID + number, *encoders[i]));
	}
}