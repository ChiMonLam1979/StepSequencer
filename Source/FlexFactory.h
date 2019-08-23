#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

namespace FlexItemFactory
{
	FlexItem makeStepChoicesButtonsBoxItem(Component& component, int numberOfChoices);

	FlexItem makeButtonItem(Component& component);

	FlexItem makeEncoderItem(Component& component);

	FlexItem makeIncButtonsItem(Component& component);
}

namespace  FlexBoxFactory
{
	FlexBox makeStepChoicesButtonsBox();

	FlexBox makeStepButtonsBox();

	FlexBox makeEncodersBox();

	FlexBox makeLeftColumnStepButtonsBox();

	FlexBox makeLeftColumnEncodersBox();

	FlexBox makeLeftColumnIncButtonsBox();

	FlexBox makeLeftColumnBox();

	FlexBox makeRightColumnBox();

	FlexBox makeCentralBox();

	FlexBox makeCentralIncButtonsBox();

	FlexBox makeMasterBox();
}