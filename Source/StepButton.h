#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class StepButton : public DrawableButton
{
public:

	StepButton(const String& name, ButtonStyle style, bool isRadioButton);
	~StepButton();

private:
	std::unique_ptr<XmlElement>	buttonNormalSvg;
	std::unique_ptr<XmlElement>	buttonOverSvg;
	std::unique_ptr<XmlElement>	buttonDownSvg;
	std::unique_ptr<XmlElement>	buttonOnSvg;
	std::unique_ptr<XmlElement>	buttonOnDownSvg;
	std::unique_ptr<XmlElement>	buttonOnOverSvg;
	std::unique_ptr<Drawable>	drawableButtonNormal;
	std::unique_ptr<Drawable>	drawableButtonOver;
	std::unique_ptr<Drawable>	drawableButtonDown;
	std::unique_ptr<Drawable>	drawableButtonOn;
	std::unique_ptr<Drawable>	drawableButtonOnDown;
	std::unique_ptr<Drawable>	drawableButtonOnOver;
};