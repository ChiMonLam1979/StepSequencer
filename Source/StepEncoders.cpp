#include "StepEncoders.h"
#include "ComponentDimensions.h"
#include "ParameterNames.h"

StepEncoders::StepEncoders(StepSequencerEngine& processor) : processor(processor)
{
	for(auto i = 0; i < 16; i++)
	{
		auto led = std::make_unique<LED>();
		encoderLeds.push_back(std::move(led));

		auto number = String(i);
		auto encoder = std::make_unique<Encoder>(ParameterNames::StepEncoderName + number, *encoderLeds[i]);
		encoders.push_back(std::move(encoder));
	}

	for(auto& encoderItem: encoders)
	{
		auto* encoder = encoderItem.get();

		addAndMakeVisible(encoder);
		encoder->onValueChange = [this, encoder] { encoderValueChanged(encoder->getName()); };
	}

	for(auto& ledItem : encoderLeds)
	{
		addAndMakeVisible(ledItem.get());
		ledItem->setState(Enums::LEDOff);
	}

	setInterceptsMouseClicks(false, true);

	AttachToParameters();
}

StepEncoders::~StepEncoders()
{
}

void StepEncoders::AttachToParameters()
{
	for (auto i = 0; i < DefaultValues::NumberOfSteps; i++)
	{
		auto number = String(i);

		stepEncoderAttachments.add(new AudioProcessorValueTreeState::SliderAttachment(processor.treeState, IDs::PitchEncoderID + number, *this->encoders[i]));
	}
}

void StepEncoders::resized()
{
	auto spaceBetweenLeds	= ComponentPositions::NumberOfPixelsBetweenEncoderLEDs;
	auto firstLEDBounds		= ComponentBounds::StepEncodersFirstLEDBounds;

	for (auto i = 0; i < 16; i++)
	{
		encoderLeds[i]->setBounds(firstLEDBounds);

		firstLEDBounds.setX(firstLEDBounds.getX() + spaceBetweenLeds);
	}
}

void StepEncoders::encoderValueChanged(const String& encoderName) const
{
	
}