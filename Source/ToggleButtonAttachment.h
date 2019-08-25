#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "ChoiceUpdaterService.h"
#include "StepButton.h"

class ToggleButtonAttachment : public Component,
							 public AudioProcessorValueTreeState::Listener
{
public:

	ToggleButtonAttachment
	(
		ChoiceUpdaterService& updaterService,
		AudioProcessorValueTreeState& treeState,
		const String& parameterId,
		const String& paramterName,
		Enums::StepButtonType buttonType
	);

	~ToggleButtonAttachment();

	void Clicked(bool value);
	void parameterChanged(const String& parameterID, float newValue) override;

private:

	AudioParameterBool*			parameter { nullptr };
	std::unique_ptr<StepButton>	button;
	ChoiceUpdaterService&		updaterService;
};