#include "health.h"
#include <algorithm>

Health::Health(int _max)
{
	max = _max;
	current = _max;
}

void Health::change_health(int value)
{
	current = std::max(0, std::min(max, current + value));
}