#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "EncoderLookAndFeel.h"
#include "LED.h"
#include "GroupEncoder.h"

class Encoder : public Slider, public Button::Listener, public Slider::Listener
{
public:

	Encoder(const String& name, LED& led, std::unique_ptr<GroupEncoder>& groupEncoder);
	~Encoder();

	void mouseEnter(const MouseEvent& event) override;

	void mouseExit(const MouseEvent& event) override;

	void buttonClicked(Button* button) override;

	void sliderValueChanged(Slider* slider) override;

	bool isCourseMode{ false };

	bool isGrouped{ false };

	LED& led;

private:

	SharedResourcePointer<EncoderLookAndFeel>	encoderLookAndFeel;

	std::unique_ptr<GroupEncoder>&					groupEncoder;
};
