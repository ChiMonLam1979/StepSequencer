#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "EncoderLookAndFeel.h"
#include "LED.h"

class GroupEncoder : public Slider
{
public:

	GroupEncoder(const String& name, LED& led);
	~GroupEncoder();

	void mouseEnter(const MouseEvent& event) override;

	void mouseExit(const MouseEvent& event) override;

	bool isCourseMode{ false };

	LED& led;

private:

	SharedResourcePointer<EncoderLookAndFeel>	encoderLookAndFeel;
};