#pragma once

#include "ship.h"

class EnemyA : public Ship
{
public:
	EnemyA(SDL_Renderer* renderer);
	~EnemyA() = default;

	void tick(float delta) override;
};

