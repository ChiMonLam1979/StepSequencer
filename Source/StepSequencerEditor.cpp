#include "StepSequencerEditor.h"
#include "Parameters.h"

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
	transportLEDs->setBounds(getLocalBounds());

	auto window = getLocalBounds();

	FlexBox buttonBox;
	buttonBox.justifyContent	= FlexBox::JustifyContent::center;
	buttonBox.alignContent		= FlexBox::AlignContent::flexEnd;

	for (auto& stepButton : stepButtons->stepButtons)
	{
		buttonBox.items.add(makeButtonBoxItem(*stepButton));
	}

	FlexItem underStepButtonsPanelItem	= makeUnderStepButtonsPanelItem(*underStepButtonsPanel);
	underStepButtonsPanelItem.alignSelf	= FlexItem::AlignSelf::center;

	FlexBox main;
	main.flexDirection = FlexBox::Direction::column;
	main.items.addArray({
								FlexItem(buttonBox).withFlex(1),
								FlexItem(underStepButtonsPanelItem)
	});

	main.performLayout(window);
}

FlexItem StepSequencerEditor::makeButtonBoxItem(Component& component)
{
	return FlexItem(component)
		.withMinHeight(ComponentSizes::StepButtonHeight)
		.withMinWidth(ComponentSizes::StepButtonWidth)
		.withMaxHeight(ComponentSizes::StepButtonHeight)
		.withMaxWidth(ComponentSizes::StepButtonWidth);
}

FlexItem StepSequencerEditor::makeUnderStepButtonsPanelItem(Component& component)
{
	return FlexItem(component)
		.withMinHeight(ComponentSizes::UnderStepButtonsPanelHeight)
		.withMaxHeight(ComponentSizes::UnderStepButtonsPanelHeight);
}