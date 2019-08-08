#include "FlexFactory.h"
#include "ComponentDimensions.h"


namespace FlexItemFactory
{
	FlexItem makeBlankSidePanelItem(Component& component)
	{
		return FlexItem(component)
			.withMinHeight	(ComponentSizes::StepButtonHeight)
			.withMinWidth	(ComponentSizes::blankSidePanelWidth)
			.withMaxHeight	(ComponentSizes::StepButtonHeight)
			.withMaxWidth	(ComponentSizes::blankSidePanelWidth);
	}

	FlexItem makeStepChoicesButtonsBoxItem(Component& component, int numberOfChoices)
	{
		return FlexItem(component)
			.withMinHeight	(ComponentSizes::StepButtonHeight)
			.withMinWidth	(ComponentSizes::StepButtonWidth * numberOfChoices)
			.withMaxHeight	(ComponentSizes::StepButtonHeight)
			.withMaxWidth	(ComponentSizes::StepButtonWidth * numberOfChoices);
	}

	FlexItem makeButtonBoxItem(Component& component)
	{
		return FlexItem(component)
			.withMinHeight	(ComponentSizes::StepButtonHeight)
			.withMinWidth	(ComponentSizes::StepButtonWidth)
			.withMaxHeight	(ComponentSizes::StepButtonHeight)
			.withMaxWidth	(ComponentSizes::StepButtonWidth);
	}

	FlexItem makeEncoderBoxItem(Component& component)
	{
		return FlexItem(component)
			.withMinHeight	(ComponentSizes::StepEncoderHeight)
			.withMinWidth	(ComponentSizes::StepEncoderWidth)
			.withMaxHeight	(ComponentSizes::StepEncoderHeight)
			.withMaxWidth	(ComponentSizes::StepEncoderWidth);
	}

	FlexItem makeUnderStepButtonsPanelItem(Component& component)
	{
		return FlexItem(component)
			.withMinHeight	(ComponentSizes::UnderStepButtonsPanelHeight)
			.withMaxHeight	(ComponentSizes::UnderStepButtonsPanelHeight)
			.withAlignSelf	(FlexItem::AlignSelf::center);
	}
}

namespace  FlexBoxFactory
{
	FlexBox makeStepChoicesButtonsBox()
	{
		FlexBox box;
		box.justifyContent = FlexBox::JustifyContent::flexStart;
		box.alignContent = FlexBox::AlignContent::flexEnd;
		return box;
	}

	FlexBox makeStepButtonsBox()
	{
		FlexBox box;
		box.justifyContent	= FlexBox::JustifyContent::center;
		box.alignContent	= FlexBox::AlignContent::flexEnd;
		return box;
	}

	FlexBox maketEncodersBox()
	{
		FlexBox box;
		box.justifyContent	= FlexBox::JustifyContent::center;
		box.alignContent	= FlexBox::AlignContent::flexEnd;
		return box;
	}

	FlexBox makeMasterBox()
	{
		FlexBox box;
		box.flexDirection = FlexBox::Direction::column;

		return box;
	}
}