#pragma once

#include "entity.h"

struct ProjectileData
{
	Entity entity;
	float fire_rate;
	float timer;
	int amount = 1;
};

class Ship : public Entity
{
public:
	Ship() = default;
	~Ship() = default;

	void fire();
	ProjectileData projectile;
};
