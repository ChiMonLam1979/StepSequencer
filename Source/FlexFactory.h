#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

namespace FlexItemFactory
{
	FlexItem makeButtonBoxItem(Component& component);

	FlexItem makeEncoderBoxItem(Component& component);

	FlexItem makeUnderStepButtonsPanelItem(Component& component);
}

namespace  FlexBoxFactory
{
	FlexBox makeStepButtonsBox();

	FlexBox maketEncodersBox();

	FlexBox makeMasterBox();
}