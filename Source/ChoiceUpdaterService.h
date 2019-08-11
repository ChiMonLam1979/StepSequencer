#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class ChoiceUpdaterService
{
public:

	ChoiceUpdaterService();
	virtual ~ChoiceUpdaterService();

	virtual void UpdateParameters(String choice) = 0;

private:

};