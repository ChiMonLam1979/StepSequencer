#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepSequencerEngine.h"
#include "StepButton.h"
#include "StepButtonsController.h"
#include "BlankPanel.h"
#include "PlayPositionLeds.h"

class StepSequencerEditor : public AudioProcessorEditor
{
public:
	StepSequencerEditor(StepSequencerEngine&);
    ~StepSequencerEditor();

    void paint (Graphics&) override;
	void resized() override;

	std::unique_ptr<BlankPanel> underStepButtonsPanel;
	std::unique_ptr<Drawable>	backPlate;

	StepButtonsController stepButtonsController;

	std::unique_ptr<OwnedArray<StepButton>> stepButtons;
	std::unique_ptr<PlayPositionLeds> playPositionLeds;

	static FlexItem makeButtonBoxItem(Component& component);
	static FlexItem makeUnderStepButtonsPanelItem(Component& component);

private:

    StepSequencerEngine& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StepSequencerEditor)
};
