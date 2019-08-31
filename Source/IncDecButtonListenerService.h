#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepEncoders.h"
#include "MasterEncoder.h"
#include "StepButtons.h"

class IncDecButtonListenerService
{
public:

	IncDecButtonListenerService(
		StepEncoders& stepEncoders,
		MasterEncoder& masterEncoder,
		StepButtons& stepIncDecButtons,
		StepButtons& masterIncDecButtons);
	~IncDecButtonListenerService();

private:

};
