#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class Pattern
{
public:

	Pattern(int trackLength, int channekl);
	~Pattern();

	int					trackLength;
	int					channel;
	std::vector<int>	notes;
	std::vector<uint8>	velocity;

private:

};