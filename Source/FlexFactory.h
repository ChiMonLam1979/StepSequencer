#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

namespace FlexItemFactory
{
	FlexItem makeBlankSidePanelItem();

	FlexItem makeStepChoicesButtonsBoxItem(Component& component, int numberOfChoices);

	FlexItem makeButtonBoxItem(Component& component);

	FlexItem makeEncoderBoxItem(Component& component);

	FlexItem makeUnderStepButtonsPanelItem(Component& component);
}

namespace  FlexBoxFactory
{
	FlexBox makeStepChoicesButtonsBox();

	FlexBox makeStepButtonsBox();

	FlexBox makeEncodersBox();

	FlexBox makeLeftColumnBox();

	FlexBox makeRightColumnBox();

	FlexBox makeCentralBox();

	FlexBox makeMasterBox();
}