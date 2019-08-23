#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepEncoders.h"

class MasterEncoder : public Slider
{
public:

	MasterEncoder(const String& name, std::unique_ptr<StepEncoders>& stepEncoders, LED& led);
	~MasterEncoder();

	void mouseEnter(const MouseEvent& event) override;

	void mouseExit(const MouseEvent& event) override;

	void mouseDown(const MouseEvent& event) override;

	void mouseDrag(const MouseEvent& event) override;

	void mouseUp(const MouseEvent& event) override;

	bool isCourseMode{ false };

	LED& led;

private:

	SharedResourcePointer<EncoderLookAndFeel>	encoderLookAndFeel;

	std::unique_ptr<StepEncoders>& stepEncoders;
};
