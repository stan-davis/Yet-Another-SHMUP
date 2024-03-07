#pragma once

#include "entity.h"
#include "projectile.h"

struct ProjectileData
{
	Projectile entity;
	float fire_rate;
	float timer;
	int amount = 1;
	int angle = 0;
};

class Ship : public Entity
{
public:
	Ship() = default;
	~Ship() = default;

	void tick(float delta) override;

	void fire();
	ProjectileData projectile;
};
