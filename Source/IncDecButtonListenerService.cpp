#include "IncDecButtonListenerService.h"

IncDecButtonListenerService::IncDecButtonListenerService(
	std::unique_ptr<StepEncoders>& stepEncoders,
	std::unique_ptr<MasterEncoder>& masterEncoder,
	std::unique_ptr<StepButtons>& stepIncDecButtons,
	std::unique_ptr<StepButtons>& masterIncDecButtons)
{
	for (auto i = 0; i < 32; i += 2)
	{
		stepIncDecButtons->stepButtons[i]->addListener(stepEncoders->encoders[i / 2].get());
		stepIncDecButtons->stepButtons[i + 1]->addListener(stepEncoders->encoders[i / 2].get());
	}

	for (auto i = 0; i < 2; i += 2)
	{
		masterIncDecButtons->stepButtons[i]->addListener(masterEncoder.get());
		masterIncDecButtons->stepButtons[i + 1]->addListener(masterEncoder.get());
	}

	for (auto i = 0; i < 16; ++i)
	{
		masterIncDecButtons->stepButtons[0]->addListener(stepEncoders->encoders[i].get());
		masterIncDecButtons->stepButtons[1]->addListener(stepEncoders->encoders[i].get());
	}
}

IncDecButtonListenerService::~IncDecButtonListenerService()
{
	
}
