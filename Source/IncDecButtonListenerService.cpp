#include "IncDecButtonListenerService.h"
#include "DefaulValues.h"

IncDecButtonListenerService::IncDecButtonListenerService(
	StepEncoders& stepEncoders,
	MasterEncoder& masterEncoder,
	StepButtons& stepIncButtons,
	StepButtons& stepDecButtons,
	StepButtons& masterIncButtons,
	StepButtons& masterDecButtons)
{
	masterIncButtons.stepButtons[0]->addListener(&masterEncoder);
	masterDecButtons.stepButtons[0]->addListener(&masterEncoder);

	for (auto i = 0; i < DefaultValues::NumberOfSteps; ++i)
	{
		masterIncButtons.stepButtons[0]->addListener(stepEncoders.encoders[i].get());
		masterDecButtons.stepButtons[0]->addListener(stepEncoders.encoders[i].get());

		stepIncButtons.stepButtons[i]->addListener(stepEncoders.encoders[i].get());
		stepDecButtons.stepButtons[i]->addListener(stepEncoders.encoders[i].get());
	}
}

IncDecButtonListenerService::~IncDecButtonListenerService()
{
	
}
