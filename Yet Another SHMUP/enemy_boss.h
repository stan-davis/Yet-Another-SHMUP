#pragma once
#include "ship.h"
class EnemyBoss : public Ship
{
public:
	EnemyBoss(SDL_Renderer* renderer);
	~EnemyBoss() = default;

	void tick(float delta) override;

private:
	int phase = 0;
	void change_phase(int value);

	ProjectileData proj_p1;
	ProjectileData proj_p2;
};

