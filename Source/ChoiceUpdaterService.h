#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class ChoiceUpdaterService
{
public:

	ChoiceUpdaterService();

	virtual ~ChoiceUpdaterService();

	virtual void UpdateParameters(int value) = 0;

private:

};