#include "enemy_boss.h"

EnemyBoss::EnemyBoss(SDL_Renderer* renderer)
{
	sprite.set_texture(renderer, "assets/sprites/Ships/spaceShips_007.png");
	health.set_max(200);
	velocity.y = 1;
	speed = 100;
	rect = sprite.rect;

	//Base projectiles
	projectile.entity.velocity.y = 1;
	projectile.entity.rotation = 180;
	projectile.entity.speed = 600;
	projectile.entity.sprite.set_texture(renderer, "assets/sprites/Missiles/spaceMissiles_009.png");
	projectile.entity.health.set_max(1);
	projectile.fire_rate = 20;
	projectile.amount = 1;
	projectile.entity.rect = projectile.entity.sprite.rect;

	//Phase 1 projectile
	proj_p1.entity.velocity.y = 1;
	proj_p1.entity.rotation = 180;
	proj_p1.entity.speed = 600;
	proj_p1.entity.sprite.set_texture(renderer, "assets/sprites/Missiles/spaceMissiles_040.png");
	proj_p1.entity.health.set_max(1);
	proj_p1.fire_rate = 50;
	proj_p1.amount = 3;
	proj_p1.angle = 1;
	proj_p1.entity.rect = projectile.entity.sprite.rect;

	//Phase 2 projectile
	proj_p2.entity.velocity.y = 1;
	proj_p2.entity.rotation = 180;
	proj_p2.entity.speed = 600;
	proj_p2.entity.sprite.set_texture(renderer, "assets/sprites/Missiles/spaceMissiles_021.png");
	proj_p2.entity.health.set_max(1);
	proj_p2.fire_rate = 20;
	proj_p2.amount = 3;
	proj_p2.angle = 1;
	proj_p2.entity.rect = projectile.entity.sprite.rect;
}

void EnemyBoss::tick(float delta)
{
	//Stop when reaching screen
	if (position.y >= 64)
		velocity.y = 0;

	//Phase change when health below certain value
	if (health.current <= 100 && phase == 0)
		change_phase(1);
	else if (health.current <= 50 && phase == 1)
		change_phase(2);

	Ship::tick(delta);
}

void EnemyBoss::change_phase(int value)
{
	switch (value)
	{
	case 1:
		projectile = proj_p1;
		break;
	case 2:
		projectile = proj_p2;
		break;
	}

	phase = value;
}
