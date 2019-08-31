#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepEncoders.h"
#include "ChoiceUpdaterService.h"

class SliderAttachmentUpdaterService : public ChoiceUpdaterService
{
public:
	SliderAttachmentUpdaterService
	(
		OwnedArray<AudioProcessorValueTreeState::SliderAttachment>& stepEncoderAttachments,
		StepEncoders&	stepEncoders,
		AudioProcessorValueTreeState& treeState
	);

	~SliderAttachmentUpdaterService();

	void UpdateParameters(int value) override;

	void AttachEncodersToPitch();
	void AttachEncodersToNoteLength();
	void AttachEncodersToVelocity();

private:

	OwnedArray<AudioProcessorValueTreeState::SliderAttachment>&	stepEncoderAttachments;
	StepEncoders&												stepEncoders;
	AudioProcessorValueTreeState&								treeState;
};
