#include "FlexFactory.h"
#include "Parameters.h"


namespace FlexItemFactory
{
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