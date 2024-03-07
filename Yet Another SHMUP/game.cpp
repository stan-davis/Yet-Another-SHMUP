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

	update_score_text();
	update_health_text();
}

void Game::tick(float delta)
{
	//Enemy collision with player projectiles
	for (auto& projectile : player->children)
	{
		for (auto& enemy : enemies)
		{
			if (!projectile->sprite.visible || !enemy->sprite.visible)
				continue;

			if (SDL_HasIntersectionF(&projectile->rect, &enemy->rect))
			{
				projectile->health.change_health(-1);
				enemy->health.change_health(-1);
				score += 1;
				update_score_text();
			}
		}
	}

	//Player collision with enemy projectiles
	for (auto& enemy : enemies)
	{
		for (auto& projectile : enemy->children)
		{
			if (!projectile->sprite.visible || !player->sprite.visible)
				continue;

			if (SDL_HasIntersectionF(&projectile->rect, &player->rect))
			{
				projectile->health.change_health(-1);
				player->health.change_health(-1);
				update_health_text();
			}
		}
	}
}

void Game::render()
{
	score_text.render(renderer, { 16 , 0 });
	high_score_text.render(renderer, { ((float)window_width / 2) - (high_score_text.rect.w / 2), 0 });
	health_text.render(renderer, { window_width - health_text.rect.w - 16, 0 });
}

void Game::update_score_text()
{
	std::string score_str = "SCORE " + std::to_string(score);
	score_text.set_text(renderer, font, score_str);

	if (score > high_score)
	{
		high_score = score;
		std::string high_score_str = "TOP " + std::to_string(high_score);
		high_score_text.set_text(renderer, font, high_score_str);
	}
}

void Game::update_health_text()
{
	std::string health_str = "HEALTH " + std::to_string(player->health.current);
	health_text.set_text(renderer, font, health_str);
}
