#pragma once
#include "EncoderLookAndFeel.h"
#include "Parameters.h"

EncoderLookAndFeel::EncoderLookAndFeel()
{
	encoderBodyImage	= encoderBodyImage.rescaled(ComponentSizes::StepEncoderWidth, ComponentSizes::StepEncoderHeight, Graphics::highResamplingQuality);
	thumbImage			= thumbImage.rescaled(ComponentSizes::StepEncoderWidth, ComponentSizes::StepEncoderHeight, Graphics::highResamplingQuality);
}

EncoderLookAndFeel::~EncoderLookAndFeel()
{
	
}

void EncoderLookAndFeel::drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider& slider)
{
	const float angle	= rotaryEndAngle + sliderPosProportional * (rotaryEndAngle - rotaryStartAngle);
	const float pivotX	= ComponentSizes::StepEncoderWidth / 2.0;
	const float pivotY	= ComponentSizes::StepEncoderHeight / 2.0;
	g.drawImage(
		encoderBodyImage,
		x,
		y,
		ComponentSizes::StepEncoderWidth,
		ComponentSizes::StepEncoderHeight,
		x,
		y,
		ComponentSizes::StepEncoderWidth,
		ComponentSizes::StepEncoderHeight);
	g.drawImageTransformed(thumbImage, AffineTransform::rotation(angle, pivotX, pivotY));
}