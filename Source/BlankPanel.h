#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class BlankPanel : public Component
{
public:
	Rectangle<float> separator;

	BlankPanel(const float width, const float height)
	{
		const Rectangle<float> separatorRectangle{ 0 ,0, width, height };
		separator = separatorRectangle;
	}
};