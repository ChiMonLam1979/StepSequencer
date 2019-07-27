#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepSequencerEngine.h"
#include "StepButtons.h"
#include "BlankPanel.h"
#include "TransportLEDs.h"
#include "StepEncoders.h"

class StepSequencerEditor : public AudioProcessorEditor
{
public:
	StepSequencerEditor(StepSequencerEngine&);
    ~StepSequencerEditor();

    void paint (Graphics&) override;
	void resized() override;

	std::unique_ptr<Drawable>			backPlate;
	std::unique_ptr<StepEncoders>		stepEncoders;
	std::unique_ptr<StepButtons>		stepButtons;
	std::unique_ptr<TransportLEDs>		transportLEDs;
	std::unique_ptr<BlankPanel>			underStepButtonsPanel;

private:

    StepSequencerEngine& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StepSequencerEditor)
};