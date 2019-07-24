#include "StepButton.h"
#include "Parameters.h"

StepButton::StepButton(const String& name, ButtonStyle style) : DrawableButton(name, style)
{
	auto buttonNormal	= Drawable::createFromImageData(BinaryData::ButtonNormal_png,	BinaryData::ButtonNormal_pngSize);
	auto buttonOver		= Drawable::createFromImageData(BinaryData::ButtonOver_png,		BinaryData::ButtonOver_pngSize);
	auto buttonDown		= Drawable::createFromImageData(BinaryData::ButtonDown_png,		BinaryData::ButtonDown_pngSize);
	auto buttonOn		= Drawable::createFromImageData(BinaryData::ButtonOn_png,		BinaryData::ButtonOn_pngSize);
	auto buttonDownOn	= Drawable::createFromImageData(BinaryData::ButtonOnDown_png,	BinaryData::ButtonOnDown_pngSize);
	auto buttonOverOn	= Drawable::createFromImageData(BinaryData::ButtonOnOver_png,	BinaryData::ButtonOnOver_pngSize);

	this->setSize(ComponentSizes::StepButtonWidth, ComponentSizes::StepButtonHeight);
	this->setImages(buttonNormal.get(), buttonOver.get(), buttonDown.get(), nullptr, buttonOn.get(), buttonOverOn.get(), buttonDownOn.get());
	this->setColour(DrawableButton::backgroundOnColourId, Colour());
	this->setClickingTogglesState(true);
}

StepButton::~StepButton()
{
	
}