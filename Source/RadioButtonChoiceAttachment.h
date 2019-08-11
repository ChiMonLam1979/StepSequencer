#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepButton.h"
#include "ChoiceUpdaterService.h"

class RadioButtonChoiceAttachment : public Component,
									public AudioProcessorValueTreeState::Listener
{
public:

	RadioButtonChoiceAttachment
	(
		ChoiceUpdaterService& updaterService,
		AudioProcessorValueTreeState& treeState,
		String& parameterId
	);

	~RadioButtonChoiceAttachment();

	void Clicked(const String& choice);
	void resized() override;
	void parameterChanged(const String& parameterID, float newValue) override;

private:

	AudioParameterChoice* parameter = nullptr;
	OwnedArray<StepButton> buttons;
	ChoiceUpdaterService& updaterService;
};
