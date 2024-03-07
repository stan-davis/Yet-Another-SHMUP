#include "enemy_a.h"

EnemyA::EnemyA(SDL_Renderer* renderer)
{
	sprite.set_texture(renderer, "assets/sprites/Ships/spaceShips_004.png");
	health.set_max(3);
	velocity.y = 1;
	speed = 100;
	rect = sprite.rect;

	projectile.entity.velocity.y = 1;
	projectile.entity.rotation = 180;
	projectile.entity.speed = 200;
	projectile.entity.sprite.set_texture(renderer, "assets/sprites/Missiles/spaceMissiles_016.png");
	projectile.entity.health.set_max(1);
	projectile.fire_rate = 50;
	projectile.amount = 1;
	projectile.entity.rect = projectile.entity.sprite.rect;
}
