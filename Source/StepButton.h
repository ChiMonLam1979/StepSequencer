#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "DrawablesCache.h"

class StepButton : public DrawableButton
{
public:

	StepButton(const String& name, ButtonStyle style, bool isRadioButton);
	~StepButton();

	SharedResourcePointer<DrawablesCache> svgCache;

private:

};