#pragma once

#include "entity.h"
#include <vector>

class Ship : public Entity
{
public:
	Ship() = default;
	~Ship() = default;
	
	void fire();
};