#pragma once

class Health
{
public:
	Health() = default;
	~Health() = default;
	
	void set_max(int _max);
	void change_health(int value);

	int max = 0;
	int current = 0;

};