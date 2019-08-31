#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "DrawablesCache.h"
#include "Enums.h"

class StepButton : public DrawableButton
{
public:

	StepButton(const String& name, ButtonStyle style, Enums::StepButtonType buttonType);

	~StepButton();

	void SetStepButtonStyle(Enums::StepButtonStyle style);

	Enums::StepButtonType buttonType;

private:

	void SetRedImages();
	void SetGreenImages();
	void SetAmberImages();
	void SetAmberSelectImages();
	void SetIncButtonImages();
	void SetDecButtonImages();
	void SetSelectAllButtonImages();

	SharedResourcePointer<DrawablesCache> svgCache;
};
