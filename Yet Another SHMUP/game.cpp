#include "game.h"
#include "enemy_a.h"

void Game::start()
{
	player = std::make_unique<Player>(renderer);
	entities.push_back(player);
	
	//Spawn enemies
	for (int i = 0; i < 7; i++)
	{
		std::shared_ptr<EnemyA> enemy = std::make_unique<EnemyA>(renderer);
		enemy->position = { 150 + 150 * (float)i, -50};
		enemies.push_back(enemy);
		entities.push_back(enemy);
	}
}

void Game::tick(float delta)
{
	for (auto& projectile : player->children)
	{
		for (auto& enemy : enemies)
		{
			if (!projectile->sprite.visible || !enemy->sprite.visible)
				continue;

			if (SDL_HasIntersectionF(&projectile->sprite.rect, &enemy->sprite.rect))
			{
				projectile->health.change_health(-1);
				enemy->health.change_health(-1);
			}
		}
	}
}