#include "Parameters.h"
#include "StepEncoders.h"

StepEncoders::StepEncoders()
{
	for(auto i = 0; i < 16; i++)
	{
		encoders.add(new Encoder(ParameterNames::StepEncoderNames[i]));
	}

	for(auto encoder: encoders)
	{
		addAndMakeVisible(encoder);
	}

	setInterceptsMouseClicks(false, true);

}

StepEncoders::~StepEncoders()
{
	
}

//void StepEncoders::resized()
//{
//	
//}