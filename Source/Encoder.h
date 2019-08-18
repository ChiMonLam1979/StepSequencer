#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "EncoderLookAndFeel.h"
#include "LED.h"

class Encoder : public Slider
{
public:

	Encoder(const String& name, LED& led);
	~Encoder();

	void mouseEnter(const MouseEvent& event) override;

	void mouseExit(const MouseEvent& event) override;

	bool isCourseMode{ false };

	LED& led;

private:

	SharedResourcePointer<EncoderLookAndFeel>	encoderLookAndFeel;

};