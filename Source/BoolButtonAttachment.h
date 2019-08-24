#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "ChoiceUpdaterService.h"
#include "StepButton.h"

class BoolButtonAttachment : public Component,
							 public AudioProcessorValueTreeState::Listener
{
public:

	BoolButtonAttachment
	(
		ChoiceUpdaterService& updaterService,
		AudioProcessorValueTreeState& treeState,
		const String& parameterId
	);

	~BoolButtonAttachment();

	void Clicked(bool value);
	void parameterChanged(const String& parameterID, float newValue) override;

private:

	AudioParameterBool*			parameter { nullptr };
	std::unique_ptr<StepButton>	button;
	ChoiceUpdaterService&		updaterService;
};