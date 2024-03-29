#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class EncoderLookAndFeel : public LookAndFeel_V4
{
public:

	EncoderLookAndFeel();
	~EncoderLookAndFeel();

	void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider& slider) override;

private:

	Image thumbImage{ ImageCache::getFromMemory(BinaryData::EncoderThumb_png, BinaryData::EncoderThumb_pngSize) };
	std::unique_ptr<XmlElement> encoderBodySvg;
	std::unique_ptr<Drawable> drawableEncoderBody;
};