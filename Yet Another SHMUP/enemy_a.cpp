#include "enemy_a.h"

EnemyA::EnemyA(SDL_Renderer* renderer)
{
	sprite.set_texture(renderer, "assets/sprites/Ships/spaceShips_004.png");
	health.set_max(3);
	velocity.y = 1;
	speed = 100;

	projectile.entity.velocity.y = 1;
	projectile.entity.speed = 600;
	projectile.entity.sprite.set_texture(renderer, "assets/sprites/Missiles/spaceMissiles_015.png");
	projectile.entity.health.set_max(1);
	projectile.fire_rate = 50;
	projectile.amount = 1;
}

void EnemyA::tick(float delta)
{
	if (!sprite.visible)
		return;

	projectile.timer--;

	if (projectile.timer < 0)
	{
		projectile.timer = projectile.fire_rate;
		fire();
	}

	Entity::tick(delta);
}
