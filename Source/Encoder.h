#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "EncoderLookAndFeel.h"
#include "LED.h"

class Encoder : public Slider, public Button::Listener
{
public:

	Encoder(const String& name, LED& led);
	~Encoder();

	void mouseEnter(const MouseEvent& event) override;

	void mouseExit(const MouseEvent& event) override;

	void buttonClicked(Button* button) override;

	bool isCourseMode{ false };

	bool isGrouped{ false };

	LED& led;

private:

	SharedResourcePointer<EncoderLookAndFeel>	encoderLookAndFeel;
};
