#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class MidiTrack
{
public:

	MidiTrack(int trackLength, int channekl);
	~MidiTrack();

	int					trackLength;
	int					channel;
	std::vector<int>	notes;
	std::vector<uint8>	velocity;

private:

};