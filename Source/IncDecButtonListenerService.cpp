#include "IncDecButtonListenerService.h"

IncDecButtonListenerService::IncDecButtonListenerService(
	StepEncoders& stepEncoders,
	MasterEncoder& masterEncoder,
	StepButtons& stepIncDecButtons,
	StepButtons& masterIncDecButtons)
{
	for (auto i = 0; i < 32; i += 2)
	{
		stepIncDecButtons.stepButtons[i]->addListener(stepEncoders.encoders[i / 2].get());
		stepIncDecButtons.stepButtons[i + 1]->addListener(stepEncoders.encoders[i / 2].get());
	}

	for (auto i = 0; i < 2; i += 2)
	{
		masterIncDecButtons.stepButtons[i]->addListener(&masterEncoder);
		masterIncDecButtons.stepButtons[i + 1]->addListener(&masterEncoder);
	}

	for (auto i = 0; i < 16; ++i)
	{
		masterIncDecButtons.stepButtons[0]->addListener(stepEncoders.encoders[i].get());
		masterIncDecButtons.stepButtons[1]->addListener(stepEncoders.encoders[i].get());
	}
}

IncDecButtonListenerService::~IncDecButtonListenerService()
{
	
}
