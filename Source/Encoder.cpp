#include "Encoder.h"
#include "EncoderLookAndFeel.h"

Encoder::Encoder(
	const String& name, 
	LED& led,
	std::unique_ptr<GroupEncoder>& groupEncoder)
	:
	Slider(name),
	led(led),
	groupEncoder(groupEncoder)
{
	setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
	setRange(0, 127, 1);
	setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	setLookAndFeel(encoderLookAndFeel);
}

Encoder::~Encoder()
{
	
}

void Encoder::mouseEnter(const MouseEvent& event)
{
	led.setState(Enums::LEDGreen);
}

void Encoder::mouseExit(const MouseEvent& event)
{
	led.setState(Enums::LEDOff);
}

void Encoder::buttonClicked(Button* button)
{
	isCourseMode = !isCourseMode;

	if(isGrouped)
	{
		groupEncoder->removeListener(this);
		isGrouped = false;
	}
	else
	{
		groupEncoder->addListener(this);
		isGrouped = true;
	}
}

void Encoder::sliderValueChanged(Slider* slider)
{
	setValue(slider->getValue());
}
