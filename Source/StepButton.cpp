#include "StepButton.h"
#include "ComponentDimensions.h"

StepButton::StepButton(const String& name, ButtonStyle style, Enums::StepButtonType buttonType) : DrawableButton(name, style), buttonType(buttonType)
{
	setSize(ComponentSizes::StepButtonWidth, ComponentSizes::StepButtonHeight);

	switch (buttonType)
	{
	case Enums::RadioButton: SetRedImages();
		break;
	case Enums::GateButton: SetGreenImages();
		break;
	case Enums::SelectorButton: SetAmberImages();
		break;
	case Enums::ToggleButton: SetAmberSelectImages();
		break;
	case Enums::IncButton: SetIncButtonImages();
		break;
	case Enums::DecButton: SetDecButtonImages();
		break;
	default: SetGreenImages();
		break;
	}

	setColour(DrawableButton::backgroundOnColourId, Colour());
	setClickingTogglesState(true);
}

StepButton::~StepButton()
{
	
}

void StepButton::SetStepButtonStyle(Enums::StepButtonStyle style)
{
	switch (style)
	{
	case Enums::Red: SetRedImages();
		break;
	case Enums::Green: SetGreenImages();
		break;
	case Enums::Amber: SetAmberImages();
		break;
	case Enums::AmberSelect: SetAmberSelectImages();
		break;
	default: SetGreenImages();
		break;
	}
}

void StepButton::SetRedImages()
{
	setImages
	(
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonNormal_svg, BinaryData::ButtonNormal_svgSize),
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonOver_svg, BinaryData::ButtonOver_svgSize),
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonDown_svg, BinaryData::ButtonDown_svgSize),
		nullptr,
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonOnRed_svg, BinaryData::ButtonOnRed_svgSize),
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonOnOverRed_svg, BinaryData::ButtonOnOverRed_svgSize),
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonOnDownRed_svg, BinaryData::ButtonOnDownRed_svgSize)
	);
}

void StepButton::SetGreenImages()
{
	setImages
	(
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonNormal_svg, BinaryData::ButtonNormal_svgSize),
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonOver_svg, BinaryData::ButtonOver_svgSize),
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonDown_svg, BinaryData::ButtonDown_svgSize),
		nullptr,
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonOn_svg, BinaryData::ButtonOn_svgSize),
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonOnOver_svg, BinaryData::ButtonOnOver_svgSize),
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonOnDown_svg, BinaryData::ButtonOnDown_svgSize)
	);
}

void StepButton::SetAmberSelectImages()
{
	setImages
	(
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonOnRed_svg, BinaryData::ButtonOnRed_svgSize),
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonOnOverRed_svg, BinaryData::ButtonOnOverRed_svgSize),
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonOnDownRed_svg, BinaryData::ButtonOnDownRed_svgSize),
		nullptr,
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonOnAmber_svg, BinaryData::ButtonOnAmber_svgSize),
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonOnOverAmber_svg, BinaryData::ButtonOnOverAmber_svgSize),
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonOnDownAmber_svg, BinaryData::ButtonOnDownAmber_svgSize)
	);
}

void StepButton::SetAmberImages()
{
	setImages
	(
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonNormal_svg, BinaryData::ButtonNormal_svgSize),
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonOver_svg, BinaryData::ButtonOver_svgSize),
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonDown_svg, BinaryData::ButtonDown_svgSize),
		nullptr,
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonOnAmber_svg, BinaryData::ButtonOnAmber_svgSize),
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonOnOverAmber_svg, BinaryData::ButtonOnOverAmber_svgSize),
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonOnDownAmber_svg, BinaryData::ButtonOnDownAmber_svgSize)
	);
}

void StepButton::SetIncButtonImages()
{
	setImages
	(
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::IncButtonNormal_svg, BinaryData::IncButtonNormal_svgSize),
		nullptr,
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::IncButtonDown_svg, BinaryData::IncButtonDown_svgSize),
		nullptr,
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::IncButtonNormal_svg, BinaryData::IncButtonNormal_svgSize),
		nullptr,
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::IncButtonDown_svg, BinaryData::IncButtonDown_svgSize)
	);
}

void StepButton::SetDecButtonImages()
{
	setImages
	(
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::DecButtonNormal_svg, BinaryData::DecButtonNormal_svgSize),
		nullptr,
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::DecButtonDown_svg, BinaryData::DecButtonDown_svgSize),
		nullptr,
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::DecButtonNormal_svg, BinaryData::DecButtonNormal_svgSize),
		nullptr,
		svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::DecButtonDown_svg, BinaryData::DecButtonDown_svgSize)
	);
}