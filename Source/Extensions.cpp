#include "Extensions.h"
#include <cmath>

namespace maths
{
	int mod(int x, int y)
	{
		return (x < 0) ? ((y + x) % y) : (x % y);
	}

	double precisionRound(double number, double precision)
	{
		return floor(number * (1.0 / precision) + 0.5) / (1.0 / precision);
	}
}