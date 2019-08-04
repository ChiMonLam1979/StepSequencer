#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

namespace FlexItemFactory
{
	FlexItem makeBlankSidePanelItem(Component& component);

	FlexItem makeStepChoicesButtonsBoxItem(Component& component, int numberOfChoices);

	FlexItem makeButtonBoxItem(Component& component);

	FlexItem makeEncoderBoxItem(Component& component);

	FlexItem makeUnderStepButtonsPanelItem(Component& component);
}

namespace  FlexBoxFactory
{
	FlexBox makeStepChoicesButtonsBox();

	FlexBox makeStepButtonsBox();

	FlexBox maketEncodersBox();

	FlexBox makeMasterBox();
}