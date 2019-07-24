#include "StepSequencerEditor.h"
#include "Parameters.h"

StepSequencerEditor::StepSequencerEditor(StepSequencerEngine& p) : AudioProcessorEditor (&p), processor (p)
{
	stepButtons					= std::make_unique<OwnedArray<StepButton>>();

	playPositionLeds = std::make_unique<PlayPositionLeds>();

	for(auto i = 0; i < 16; i++)
	{
		stepButtons					->add(std::make_unique<StepButton>(ParameterNames::StepButtonNames[i], DrawableButton::ButtonStyle::ImageFitted));
	}

	underStepButtonsPanel = std::make_unique<BlankPanel>(ComponentSizes::windowWidth, ComponentSizes::UnderStepButtonsPanelHeight);

	backPlate = Drawable::createFromImageData(BinaryData::BackPanel_png, BinaryData::BackPanel_pngSize);

    setSize (ComponentSizes::windowWidth, ComponentSizes::windowHeight);
}

StepSequencerEditor::~StepSequencerEditor()
{
}

void StepSequencerEditor::paint (Graphics& g)
{
	backPlate->drawWithin(g, getLocalBounds().toFloat(), RectanglePlacement(64), 1.0f);
	addAndMakeVisible(backPlate.get());

	addAndMakeVisible(underStepButtonsPanel.get());

	auto stepController = stepButtonsController;

	for (auto& stepButton : *stepButtons)
	{
		stepButton->onClick = [stepController, stepButton] { stepController.StepClicked(stepButton->getName()); };
		addAndMakeVisible(stepButton);
		stepButton->toFront(false);
	}

	addAndMakeVisible(playPositionLeds.get());
	playPositionLeds->setBounds(getLocalBounds());
	playPositionLeds->paintLeds(g);
}

void StepSequencerEditor::resized()
{
	auto window = getLocalBounds();

	FlexBox buttonBox;
	buttonBox.justifyContent	= FlexBox::JustifyContent::center;
	buttonBox.alignContent		= FlexBox::AlignContent::flexEnd;

	for(auto& stepButton : *stepButtons)
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