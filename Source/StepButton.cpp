#include "StepButton.h"
#include "ComponentDimensions.h"

StepButton::StepButton(const String& name, ButtonStyle style, bool isRadioButton) : DrawableButton(name, style)
{
	setSize(ComponentSizes::StepButtonWidth, ComponentSizes::StepButtonHeight);

	isRadioButton ?
		setImages
		(
			svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonNormal_svg, BinaryData::ButtonNormal_svgSize),
			svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonOver_svg, BinaryData::ButtonOver_svgSize),
			svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonDown_svg, BinaryData::ButtonDown_svgSize),
			nullptr,
			svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonOnRed_svg, BinaryData::ButtonOnRed_svgSize),
			svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonOnOverRed_svg, BinaryData::ButtonOnOverRed_svgSize),
			svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::ButtonOnDownRed_svg, BinaryData::ButtonOnDownRed_svgSize)
		) :
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

	setColour(DrawableButton::backgroundOnColourId, Colour());
	setClickingTogglesState(true);
}

StepButton::~StepButton()
{
	
}