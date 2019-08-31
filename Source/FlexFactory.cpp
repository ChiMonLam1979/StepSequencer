#include "FlexFactory.h"
#include "ComponentDimensions.h"


namespace FlexItemFactory
{
	FlexItem makeStepChoicesButtonsBoxItem(Component& component, int numberOfChoices)
	{
		return FlexItem(component)
			.withMinHeight	(ComponentSizes::StepButtonHeight)
			.withMinWidth	(ComponentSizes::StepButtonWidth * numberOfChoices)
			.withMaxHeight	(ComponentSizes::StepButtonHeight)
			.withMaxWidth	(ComponentSizes::StepButtonWidth * numberOfChoices);
	}

	FlexItem makeButtonItem(Component& component)
	{
		return FlexItem(component)
			.withMinHeight	(ComponentSizes::StepButtonHeight)
			.withMinWidth	(ComponentSizes::StepButtonWidth)
			.withMaxHeight	(ComponentSizes::StepButtonHeight)
			.withMaxWidth	(ComponentSizes::StepButtonWidth);
	}

	FlexItem makeEncoderItem(Component& component)
	{
		return FlexItem(component)
			.withMinHeight	(ComponentSizes::StepEncoderHeight)
			.withMinWidth	(ComponentSizes::StepEncoderWidth)
			.withMaxHeight	(ComponentSizes::StepEncoderHeight)
			.withMaxWidth	(ComponentSizes::StepEncoderWidth);
	}

	FlexItem makeIncDecButtonsItem(Component& component)
	{
		return FlexItem(component)
			.withMinHeight(ComponentSizes::IncButtonHeight)
			.withMinWidth(ComponentSizes::IncButtonWidth)
			.withMaxHeight(ComponentSizes::IncButtonHeight)
			.withMaxWidth(ComponentSizes::IncButtonWidth).withMargin({0, -4, 0, -4});
	}

	FlexItem makeDecButtonsItem(Component& component)
	{
		return FlexItem(component)
			.withMinHeight(ComponentSizes::IncButtonHeight)
			.withMinWidth(ComponentSizes::IncButtonWidth)
			.withMaxHeight(ComponentSizes::IncButtonHeight)
			.withMaxWidth(ComponentSizes::IncButtonWidth).withMargin({ 0, 4, 0, -4 });
	}

	FlexItem makeIncButtonsItem(Component& component)
	{
		return FlexItem(component)
			.withMinHeight(ComponentSizes::IncButtonHeight)
			.withMinWidth(ComponentSizes::IncButtonWidth)
			.withMaxHeight(ComponentSizes::IncButtonHeight)
			.withMaxWidth(ComponentSizes::IncButtonWidth).withMargin({ 0, -4, 0, 4 });
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
		box.justifyContent	= FlexBox::JustifyContent::flexStart;
		box.alignContent	= FlexBox::AlignContent::flexEnd;
		return box;
	}

	FlexBox makeEncodersBox()
	{
		FlexBox box;
		box.justifyContent	= FlexBox::JustifyContent::flexStart;
		box.alignContent	= FlexBox::AlignContent::flexEnd;
		return box;
	}

	FlexBox makeLeftColumnStepButtonsBox()
	{
		FlexBox box;
		box.justifyContent = FlexBox::JustifyContent::center;
		box.alignContent = FlexBox::AlignContent::flexEnd;
		return box;
	}

	FlexBox makeLeftColumnEncodersBox()
	{
		FlexBox box;
		box.justifyContent = FlexBox::JustifyContent::center;
		box.alignContent = FlexBox::AlignContent::flexEnd;
		return box;
	}

	FlexBox makeLeftColumnIncButtonsBox()
	{
		FlexBox box;
		box.justifyContent = FlexBox::JustifyContent::center;

		return box;
	}

	FlexBox makeLeftColumnBox()
	{
		FlexBox box;
		box.flexDirection = FlexBox::Direction::column;
		box.alignContent = FlexBox::AlignContent::center;

		return box;
	}

	FlexBox makeRightColumnBox()
	{
		FlexBox box;
		box.flexDirection = FlexBox::Direction::column;

		return box;
	}

	FlexBox makeCentralBox()
	{
		FlexBox box;
		box.flexDirection = FlexBox::Direction::column;

		return box;
	}

	FlexBox makeCentralColumnBox()
	{
		FlexBox box;
		box.flexDirection = FlexBox::Direction::column;

		return box;
	}

	FlexBox makeCentralIncButtonsBox()
	{
		FlexBox box;
		box.flexDirection = FlexBox::Direction::row;
		box.justifyContent = FlexBox::JustifyContent::spaceBetween;

		return box;
	}

	FlexBox makeMasterBox()
	{
		FlexBox box;
		box.flexDirection = FlexBox::Direction::row;

		return box;
	}
}