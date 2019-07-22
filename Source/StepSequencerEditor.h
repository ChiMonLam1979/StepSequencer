#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepSequencerEngine.h"
#include "StepButton.h"
#include "StepButtonsController.h"

class StepSequencerEditor : public AudioProcessorEditor
{
public:
	StepSequencerEditor(StepSequencerEngine&);
    ~StepSequencerEditor();

    void paint (Graphics&) override;
    void resized() override;

	std::unique_ptr<StepButton> stepButtonOne;
	std::unique_ptr<StepButton> stepButtonTwo;
	std::unique_ptr<StepButton> stepButtonThree;
	std::unique_ptr<StepButton> stepButtonFour;
	std::unique_ptr<StepButton> stepButtonFive;
	std::unique_ptr<StepButton> stepButtonSix;
	std::unique_ptr<StepButton> stepButtonSeven;
	std::unique_ptr<StepButton> stepButtonEight;
	std::unique_ptr<StepButton> stepButtonNine;
	std::unique_ptr<StepButton> stepButtonTen;
	std::unique_ptr<StepButton> stepButtonEleven;
	std::unique_ptr<StepButton> stepButtonTwelve;
	std::unique_ptr<StepButton> stepButtonThirteen;
	std::unique_ptr<StepButton> stepButtonFourteen;
	std::unique_ptr<StepButton> stepButtonFifteen;
	std::unique_ptr<StepButton> stepButtonSixteen;

	//std::unique_ptr<Drawable> backPlate;

	StepButtonsController stepButtonsController;

	static FlexItem makeButtonBoxItem(Component& component);

private:

    StepSequencerEngine& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StepSequencerEditor)
};