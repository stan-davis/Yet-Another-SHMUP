#pragma once

class Health
{
public:
	Health(int _max);
	~Health() = default;

	int max = 0;
	int current = 0;
};