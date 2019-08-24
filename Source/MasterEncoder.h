#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepEncoders.h"

class MasterEncoder : public Slider, public Button::Listener
{
public:

	MasterEncoder(const String& name, std::unique_ptr<StepEncoders>& stepEncoders, LED& led);
	~MasterEncoder();

	void mouseEnter(const MouseEvent& event) override;

	void mouseExit(const MouseEvent& event) override;

	void mouseDown(const MouseEvent& event) override;

	void mouseDrag(const MouseEvent& event) override;

	void mouseUp(const MouseEvent& event) override;

	void mouseWheelMove(const MouseEvent& event, const MouseWheelDetails& wheel) override;

	void buttonClicked(Button* button) override;

	void ForwardMouseEvent(const MouseEvent& event, Enums::MouseEventType mouseEventType, const MouseWheelDetails& wheel = MouseWheelDetails{});

	bool isCourseMode{ false };

	LED& led;

private:

	SharedResourcePointer<EncoderLookAndFeel>	encoderLookAndFeel;

	std::unique_ptr<StepEncoders>& stepEncoders;
};
