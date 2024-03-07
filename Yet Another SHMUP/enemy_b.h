#pragma once

#include "ship.h"

class EnemyB : public Ship
{
public:
	EnemyB(SDL_Renderer* renderer);
	~EnemyB() = default;

	void tick(float delta) override;
};

