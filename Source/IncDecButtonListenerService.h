#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepEncoders.h"
#include "MasterEncoder.h"
#include "StepButtons.h"

class IncDecButtonListenerService
{
public:

	IncDecButtonListenerService(
		std::unique_ptr<StepEncoders>& stepEncoders,
		std::unique_ptr<MasterEncoder>& masterEncoder,
		std::unique_ptr<StepButtons>& stepIncDecButtons,
		std::unique_ptr<StepButtons>& masterIncDecButtons);
	~IncDecButtonListenerService();

private:

};
