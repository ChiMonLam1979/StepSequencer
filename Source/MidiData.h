#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class MidiData
{
public:

	MidiData();
	~MidiData();

	std::vector<int>	notes		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<uint8>	velocity	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int					channel		{ 1 };

private:

};