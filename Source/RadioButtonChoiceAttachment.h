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
		const String& parameterId
	);

	~RadioButtonChoiceAttachment();

	void resized() override;

private:

	void parameterChanged(const String& parameterID, float newValue) override;
	void Clicked(const String& choice);

	AudioProcessorValueTreeState&	treeState;
	const String&					parameterId;
	AudioParameterChoice*			parameter { nullptr };
	OwnedArray<StepButton>			buttons;
	ChoiceUpdaterService&			updaterService;
};