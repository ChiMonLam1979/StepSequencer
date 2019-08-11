#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "EncoderLookAndFeel.h"
#include "LED.h"

class Encoder : public Slider
{
public:

	Encoder(const String& name, LED& led, EncoderLookAndFeel& encoderLookAndFeel);
	~Encoder();

	void mouseEnter(const MouseEvent& event) override;

	void mouseExit(const MouseEvent& event) override;

	void mouseUp(const MouseEvent& event) override;

	EncoderLookAndFeel& encoderLookAndFeel;

	LED& led;

private:
};