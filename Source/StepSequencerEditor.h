#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepSequencerEngine.h"
#include "StepButtons.h"
#include "BlankPanel.h"
#include "PlayPositionLeds.h"
#include "LedTimer.h"

class StepSequencerEditor : public AudioProcessorEditor
{
public:
	StepSequencerEditor(StepSequencerEngine&);
    ~StepSequencerEditor();

    void paint (Graphics&) override;
	void resized() override;

	std::unique_ptr<Drawable>			backPlate;
	std::unique_ptr<StepButtons>		stepButtons;
	std::unique_ptr<TransportLEDs>		transportLEDs;
	std::unique_ptr<BlankPanel>			underStepButtonsPanel;
	std::unique_ptr<LedTimer>			ledTimer;

	static FlexItem makeButtonBoxItem(Component& component);
	static FlexItem makeUnderStepButtonsPanelItem(Component& component);

private:

    StepSequencerEngine& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StepSequencerEditor)
};