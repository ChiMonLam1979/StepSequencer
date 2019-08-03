#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepButton.h"
#include "StepEncoders.h"

class StepChoicesAttachment : public Component,
							  public AudioProcessorValueTreeState::Listener
{
public:

	StepChoicesAttachment
	(
		OwnedArray<AudioProcessorValueTreeState::SliderAttachment>& stepEncoderAttachments,
		std::unique_ptr<StepEncoders>&	stepEncoders,
		AudioProcessorValueTreeState& treeState,
		String& parameterId
	);

	~StepChoicesAttachment();

	void Clicked(const String& choice);
	void resized() override;
	void parameterChanged(const String& parameterID, float newValue) override;
	void StepChoicesAttachment::AttachEncodersToPitch();
	void StepChoicesAttachment::AttachEncodersToVelocity();

private:

	AudioParameterChoice* parameter = nullptr;
	OwnedArray<StepButton> buttons;
	OwnedArray<AudioProcessorValueTreeState::SliderAttachment>& stepEncoderAttachments;
	std::unique_ptr<StepEncoders>&	stepEncoders;
	AudioProcessorValueTreeState& treeState;
	String& parameterId;
};
