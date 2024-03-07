#pragma once

#include "entity.h"

class Projectile : public Entity
{
public:
	Projectile() = default;
	~Projectile() = default;

	void tick(float delta) override;
};

