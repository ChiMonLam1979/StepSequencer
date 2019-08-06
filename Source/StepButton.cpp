#include "StepButton.h"
#include "ComponentDimensions.h"

StepButton::StepButton(const String& name, ButtonStyle style, bool isRadioButton) : DrawableButton(name, style)
{
	buttonNormalSvg			= XmlDocument::parse(BinaryData::ButtonNormal_svg);
	buttonOverSvg			= XmlDocument::parse(BinaryData::ButtonOver_svg);
	buttonDownSvg			= XmlDocument::parse(BinaryData::ButtonDown_svg);
	buttonOnSvg				= XmlDocument::parse(isRadioButton ? BinaryData::ButtonOnRed_svg : BinaryData::ButtonOn_svg);
	buttonOnDownSvg			= XmlDocument::parse(isRadioButton ? BinaryData::ButtonOnDownRed_svg : BinaryData::ButtonOnDown_svg);
	buttonOnOverSvg			= XmlDocument::parse(isRadioButton ? BinaryData::ButtonOnOverRed_svg : BinaryData::ButtonOnOver_svg);

	drawableButtonNormal	= Drawable::createFromSVG(*buttonNormalSvg);
	drawableButtonOver		= Drawable::createFromSVG(*buttonOverSvg);
	drawableButtonDown		= Drawable::createFromSVG(*buttonDownSvg);
	drawableButtonOn		= Drawable::createFromSVG(*buttonOnSvg);
	drawableButtonOnDown	= Drawable::createFromSVG(*buttonOnDownSvg);
	drawableButtonOnOver	= Drawable::createFromSVG(*buttonOnOverSvg);

	setSize(ComponentSizes::StepButtonWidth, ComponentSizes::StepButtonHeight);
	setImages
	(
		drawableButtonNormal.get(),
		drawableButtonOver.get(),
		drawableButtonDown.get(),
		nullptr,
	    drawableButtonOn.get(),
		drawableButtonOnOver.get(),
		drawableButtonOnDown.get()
	);

	setColour(DrawableButton::backgroundOnColourId, Colour());
	setClickingTogglesState(true);
}

StepButton::~StepButton()
{
	
}