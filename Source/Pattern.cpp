
#include "Pattern.h"

Pattern::Pattern(int trackLength, int channel) : trackLength(trackLength), channel(channel)
{
	notes.reserve(trackLength);
	noteLengths.reserve(trackLength);
	velocities.reserve(trackLength);
	gates.reserve(trackLength);

	notes		= std::vector<int>(trackLength);
	noteLengths	= std::vector<int>(trackLength);
	velocities	= std::vector<uint8>(trackLength);
	gates		= std::vector<bool>(trackLength);
}

Pattern::~Pattern()
{
}