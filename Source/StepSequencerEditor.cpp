#include "StepSequencerEditor.h"

StepSequencerEditor::StepSequencerEditor(StepSequencerEngine& p) : AudioProcessorEditor (&p), processor (p)
{
    setSize (400, 300);
}

StepSequencerEditor::~StepSequencerEditor()
{
}

void StepSequencerEditor::paint (Graphics& g)
{
	g.fillAll(Colours::black);
}

void StepSequencerEditor::resized()
{
}