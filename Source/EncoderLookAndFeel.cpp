#pragma once
#include "EncoderLookAndFeel.h"
#include "ComponentDimensions.h"

EncoderLookAndFeel::EncoderLookAndFeel()
{
	thumbImage = thumbImage.rescaled(ComponentSizes::StepEncoderWidth, ComponentSizes::StepEncoderHeight, Graphics::highResamplingQuality);
}

EncoderLookAndFeel::~EncoderLookAndFeel()
{
	
}

void EncoderLookAndFeel::drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider& slider)
{
	const float angle				= rotaryEndAngle + sliderPosProportional * (rotaryEndAngle - rotaryStartAngle);
	const float pivotX				= ComponentSizes::StepEncoderWidth / 2.0;
	const float pivotY				= ComponentSizes::StepEncoderHeight / 2.0;
	const auto	bounds				= new Rectangle<int>{ x, y, ComponentSizes::StepEncoderWidth ,ComponentSizes::StepEncoderHeight };
	const auto	drawableEncoderBody = svgCache->GetOrUpdateDrawableFromCache((void*)BinaryData::EncoderBody_svg, BinaryData::EncoderBody_svgSize);

	drawableEncoderBody->drawWithin(g, bounds->toFloat(), RectanglePlacement(), 1);
	g.drawImageTransformed(thumbImage, AffineTransform::rotation(angle, pivotX, pivotY));
}