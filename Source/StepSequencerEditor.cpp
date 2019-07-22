#include "StepSequencerEditor.h"
#include "Parameters.h"

StepSequencerEditor::StepSequencerEditor(StepSequencerEngine& p) : AudioProcessorEditor (&p), processor (p)
{
	stepButtonOne = std::make_unique<StepButton>(ParameterNames::StepButtonOneName, DrawableButton::ButtonStyle::ImageFitted);
	stepButtonTwo = std::make_unique<StepButton>(ParameterNames::StepButtonTwoName, DrawableButton::ButtonStyle::ImageFitted);
	stepButtonThree = std::make_unique<StepButton>(ParameterNames::StepButtonThreeName, DrawableButton::ButtonStyle::ImageFitted);
	stepButtonFour = std::make_unique<StepButton>(ParameterNames::StepButtonFourName, DrawableButton::ButtonStyle::ImageFitted);
	stepButtonFive = std::make_unique<StepButton>(ParameterNames::StepButtonFiveName, DrawableButton::ButtonStyle::ImageFitted);
	stepButtonSix = std::make_unique<StepButton>(ParameterNames::StepButtonSixName, DrawableButton::ButtonStyle::ImageFitted);
	stepButtonSeven = std::make_unique<StepButton>(ParameterNames::StepButtonSevenName, DrawableButton::ButtonStyle::ImageFitted);
	stepButtonEight = std::make_unique<StepButton>(ParameterNames::StepButtonEightName, DrawableButton::ButtonStyle::ImageFitted);
	stepButtonNine = std::make_unique<StepButton>(ParameterNames::StepButtonNineName, DrawableButton::ButtonStyle::ImageFitted);
	stepButtonTen = std::make_unique<StepButton>(ParameterNames::StepButtonTenName, DrawableButton::ButtonStyle::ImageFitted);
	stepButtonEleven = std::make_unique<StepButton>(ParameterNames::StepButtonElevenName, DrawableButton::ButtonStyle::ImageFitted);
	stepButtonTwelve = std::make_unique<StepButton>(ParameterNames::StepButtonTwelveName, DrawableButton::ButtonStyle::ImageFitted);
	stepButtonThirteen = std::make_unique<StepButton>(ParameterNames::StepButtonThirteenName, DrawableButton::ButtonStyle::ImageFitted);
	stepButtonFourteen = std::make_unique<StepButton>(ParameterNames::StepButtonFourteenName, DrawableButton::ButtonStyle::ImageFitted);
	stepButtonFifteen = std::make_unique<StepButton>(ParameterNames::StepButtonFifteenName, DrawableButton::ButtonStyle::ImageFitted);
	stepButtonSixteen = std::make_unique<StepButton>(ParameterNames::StepButtonSixteenName, DrawableButton::ButtonStyle::ImageFitted);

	//backPlate = Drawable::createFromImageData(BinaryData::SmoothPlate_png, BinaryData::SmoothPlate_pngSize);

	auto stepController = stepButtonsController;

	stepButtonOne->onClick = [stepController, this] { stepController.StepClicked(stepButtonOne->getName()); };
	stepButtonTwo->onClick = [stepController, this] { stepController.StepClicked(stepButtonTwo->getName()); };
	stepButtonThree->onClick = [stepController, this] { stepController.StepClicked(stepButtonThree->getName()); };
	stepButtonFour->onClick = [stepController, this] { stepController.StepClicked(stepButtonFour->getName()); };
	stepButtonFive->onClick = [stepController, this] { stepController.StepClicked(stepButtonFive->getName()); };
	stepButtonSix->onClick = [stepController, this] { stepController.StepClicked(stepButtonSix->getName()); };
	stepButtonSeven->onClick = [stepController, this] { stepController.StepClicked(stepButtonSeven->getName()); };
	stepButtonEight->onClick = [stepController, this] { stepController.StepClicked(stepButtonEight->getName()); };
	stepButtonNine->onClick = [stepController, this] { stepController.StepClicked(stepButtonNine->getName()); };
	stepButtonTen->onClick = [stepController, this] { stepController.StepClicked(stepButtonTen->getName()); };
	stepButtonEleven->onClick = [stepController, this] { stepController.StepClicked(stepButtonEleven->getName()); };
	stepButtonTwelve->onClick = [stepController, this] { stepController.StepClicked(stepButtonTwelve->getName()); };
	stepButtonThirteen->onClick = [stepController, this] { stepController.StepClicked(stepButtonThirteen->getName()); };
	stepButtonFourteen->onClick = [stepController, this] { stepController.StepClicked(stepButtonFourteen->getName()); };
	stepButtonFifteen->onClick = [stepController, this] { stepController.StepClicked(stepButtonFifteen->getName()); };
	stepButtonSixteen->onClick = [stepController, this] { stepController.StepClicked(stepButtonSixteen->getName()); };

    setSize (1040, 500);

	addAndMakeVisible(stepButtonOne.get());
	addAndMakeVisible(stepButtonTwo.get());
	addAndMakeVisible(stepButtonThree.get());
	addAndMakeVisible(stepButtonFour.get());
	addAndMakeVisible(stepButtonFive.get());
	addAndMakeVisible(stepButtonSix.get());
	addAndMakeVisible(stepButtonSeven.get());
	addAndMakeVisible(stepButtonEight.get());
	addAndMakeVisible(stepButtonNine.get());
	addAndMakeVisible(stepButtonTen.get());
	addAndMakeVisible(stepButtonEleven.get());
	addAndMakeVisible(stepButtonTwelve.get());
	addAndMakeVisible(stepButtonThirteen.get());
	addAndMakeVisible(stepButtonFourteen.get());
	addAndMakeVisible(stepButtonFifteen.get());
	addAndMakeVisible(stepButtonSixteen.get());

	//addAndMakeVisible(backPlate.get());
}

StepSequencerEditor::~StepSequencerEditor()
{
}

void StepSequencerEditor::paint (Graphics& g)
{
	//backPlate->drawWithin(g, getLocalBounds().toFloat(), RectanglePlacement(64), 1.0f);
	g.fillAll(Colour(200, 201, 187));
	stepButtonOne->toFront(false);
	stepButtonTwo->toFront(false);
	stepButtonThree->toFront(false);
	stepButtonFour->toFront(false);
	stepButtonFive->toFront(false);
	stepButtonSix->toFront(false);
	stepButtonSeven->toFront(false);
	stepButtonEight->toFront(false);
	stepButtonNine->toFront(false);
	stepButtonTen->toFront(false);
	stepButtonEleven->toFront(false);
	stepButtonTwelve->toFront(false);
	stepButtonThirteen->toFront(false);
	stepButtonFourteen->toFront(false);
	stepButtonFifteen->toFront(false);
	stepButtonSixteen->toFront(false);
}

void StepSequencerEditor::resized()
{
	auto window = getLocalBounds();

	FlexBox buttonBox;
	buttonBox.justifyContent = FlexBox::JustifyContent::flexStart;
	buttonBox.alignContent = FlexBox::AlignContent::flexEnd;
	buttonBox.items.addArray({ 
								makeButtonBoxItem(*stepButtonOne),
								makeButtonBoxItem(*stepButtonTwo),
								makeButtonBoxItem(*stepButtonThree),
								makeButtonBoxItem(*stepButtonFour),
								makeButtonBoxItem(*stepButtonFive),
								makeButtonBoxItem(*stepButtonSix),
								makeButtonBoxItem(*stepButtonSeven),
								makeButtonBoxItem(*stepButtonEight),
								makeButtonBoxItem(*stepButtonNine),
								makeButtonBoxItem(*stepButtonTen),
								makeButtonBoxItem(*stepButtonEleven),
								makeButtonBoxItem(*stepButtonTwelve),
								makeButtonBoxItem(*stepButtonThirteen),
								makeButtonBoxItem(*stepButtonFourteen),
								makeButtonBoxItem(*stepButtonFifteen),
								makeButtonBoxItem(*stepButtonSixteen),
	});

	FlexBox main;
	main.flexDirection = FlexBox::Direction::column;
	main.items.addArray({
								FlexItem(buttonBox).withFlex(1),
		});

	main.performLayout(window);
}

FlexItem StepSequencerEditor::makeButtonBoxItem(Component& component)
{
	return FlexItem(component)
	.withMinHeight(ComponentSizes::StepButtonHeight)
	.withMinWidth(ComponentSizes::StepButtonWidth)
	.withMaxHeight(ComponentSizes::StepButtonHeight)
	.withMaxWidth(ComponentSizes::StepButtonWidth)
	.withFlex(1);
}