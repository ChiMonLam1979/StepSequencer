#pragma once

class ChoiceUpdaterService
{
public:

	ChoiceUpdaterService();

	virtual ~ChoiceUpdaterService();

	virtual void UpdateParameters(int value) = 0;

private:

};