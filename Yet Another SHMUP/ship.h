#pragma once

#include "entity.h"

class Ship : public Entity
{
public:
	Ship() = default;
	~Ship() = default;

	void tick(float delta) override;
};