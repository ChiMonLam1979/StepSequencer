#include "StepSequencerEditor.h"
#include "Parameters.h"
#include "FlexFactory.h"

StepSequencerEditor::StepSequencerEditor(StepSequencerEngine& p) : AudioProcessorEditor (&p), processor (p)
{
	backPlate				= Drawable::createFromImageData(BinaryData::BackPanel_png, BinaryData::BackPanel_pngSize);
	stepButtons				= std::make_unique<StepButtons>();
	transportLEDs			= std::make_unique<TransportLEDs>(p);
	underStepButtonsPanel	= std::make_unique<BlankPanel>(ComponentSizes::windowWidth, ComponentSizes::UnderStepButtonsPanelHeight);

    setSize (ComponentSizes::windowWidth, ComponentSizes::windowHeight);

	addAndMakeVisible(backPlate.get());
	stepButtons->MakeVisible(*this);
	addAndMakeVisible(transportLEDs.get());
	addAndMakeVisible(underStepButtonsPanel.get());
}

StepSequencerEditor::~StepSequencerEditor()
{
}

void StepSequencerEditor::paint (Graphics& g)
{
	backPlate->drawWithin(g, getLocalBounds().toFloat(), RectanglePlacement(64), 1.0f);
}

void StepSequencerEditor::resized()
{
	transportLEDs->setBounds(ComponentBounds::TransportLEDStripBounds);

	auto window = getLocalBounds();

	FlexBox buttonBox = FlexBoxFactory::makeStepButtonsBox();

	for (auto& stepButton : stepButtons->stepButtons)
	{
		buttonBox.items.add(FlexItemFactory::makeButtonBoxItem(*stepButton));
	}

	FlexItem underStepButtonsPanelItem	= FlexItemFactory::makeUnderStepButtonsPanelItem(*underStepButtonsPanel);

	FlexBox main = FlexBoxFactory::makeMasterBox();
	main.items.addArray({
								FlexItem(buttonBox).withFlex(1),
								FlexItem(underStepButtonsPanelItem)
	});

	main.performLayout(window);
}