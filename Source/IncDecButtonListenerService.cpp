#include "IncDecButtonListenerService.h"
#include "DefaulValues.h"

IncDecButtonListenerService::IncDecButtonListenerService(
	StepEncoders& stepEncoders,
	MasterEncoder& masterEncoder,
	StepButtons& stepIncButtons,
	StepButtons& stepDecButtons,
	StepButton& masterIncButton,
	StepButton& masterDecButton)
{
	masterIncButton.addListener(&masterEncoder);
	masterDecButton.addListener(&masterEncoder);

	for (auto i = 0; i < DefaultValues::NumberOfSteps; ++i)
	{
		masterIncButton.addListener(stepEncoders.encoders[i].get());
		masterDecButton.addListener(stepEncoders.encoders[i].get());

		stepIncButtons.stepButtons[i]->addListener(stepEncoders.encoders[i].get());
		stepDecButtons.stepButtons[i]->addListener(stepEncoders.encoders[i].get());
	}
}

IncDecButtonListenerService::~IncDecButtonListenerService()
{
	
}
