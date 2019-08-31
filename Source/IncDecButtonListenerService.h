#pragma once
#include "StepEncoders.h"
#include "MasterEncoder.h"
#include "StepButtons.h"

class IncDecButtonListenerService
{
public:

	IncDecButtonListenerService(
		StepEncoders& stepEncoders,
		MasterEncoder& masterEncoder,
		StepButtons& stepIncButtons,
		StepButtons& stepDecButtons,
		StepButtons& masterIncButtons,
		StepButtons& masterDecButtons);

	~IncDecButtonListenerService();

private:

};
