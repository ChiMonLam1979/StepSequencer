#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "DrawablesCache.h"
#include "Enums.h"

class StepButton : public DrawableButton
{
public:

	StepButton(const String& name, ButtonStyle style, bool isRadioButton);
	~StepButton();

	void SetStepButtonStyle(Enums::StepButtonStyle style);

private:

	void SetRedImages();
	void SetGreenImages();

	SharedResourcePointer<DrawablesCache> svgCache;
};
