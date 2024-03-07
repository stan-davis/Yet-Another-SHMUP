#include "enemy_b.h"

EnemyB::EnemyB(SDL_Renderer* renderer)
{
	sprite.set_texture(renderer, "assets/sprites/Ships/spaceShips_005.png");
	health.set_max(3);
	velocity.y = 1;
	speed = 150;
	rect = sprite.rect;

	projectile.entity.velocity.y = 1;
	projectile.entity.rotation = 180;
	projectile.entity.speed = 400;
	projectile.entity.sprite.set_texture(renderer, "assets/sprites/Missiles/spaceMissiles_017.png");
	projectile.entity.health.set_max(1);
	projectile.fire_rate = 100;
	projectile.amount = 2;
	projectile.entity.rect = projectile.entity.sprite.rect;
}

void EnemyB::tick(float delta)
{
	//Movement pattern example
	velocity.x = sinf(position.y / speed);
	float mag = SDL_sqrtf((velocity.x * velocity.x) + (velocity.y * velocity.y));
	velocity.x /= mag;

	Ship::tick(delta);
}
