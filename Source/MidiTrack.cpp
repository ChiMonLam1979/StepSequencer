#include "MidiTrack.h"

MidiTrack::MidiTrack(int trackLength, int channel) : trackLength(trackLength), channel(channel)
{
	notes.reserve(trackLength);
	velocity.reserve(trackLength);

	notes	 = std::vector<int>(trackLength);
	velocity = std::vector<uint8>(trackLength);
}

MidiTrack::~MidiTrack()
{
}