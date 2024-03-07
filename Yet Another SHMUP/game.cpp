#include "game.h"
#include "enemy_a.h"
#include "enemy_b.h"

void Game::start()
{
	player = std::make_unique<Player>(renderer);
	entities.push_back(player);
	
	//Level (would be better to parse some file for level data)
	for (int i = 0; i < 6; i++)
	{
		std::shared_ptr<EnemyA> enemy = std::make_unique<EnemyA>(renderer);
		enemy->position = { 150 + 150 * (float)i, -200};
		enemies.push_back(enemy);
		entities.push_back(enemy);
	}

	//Level (would be better to parse some file for level data)
	for (int i = 0; i < 4; i++)
	{
		std::shared_ptr<EnemyB> enemy = std::make_unique<EnemyB>(renderer);
		enemy->position = { 300 + 150 * (float)i, -1200 };
		enemies.push_back(enemy);
		entities.push_back(enemy);
	}

	boss = std::make_unique<EnemyBoss>(renderer);
	boss->position = { (window_width / 2) - boss->sprite.center.x, -1200 };
	enemies.push_back(boss);
	entities.push_back(boss);

	game_over_text.set_text(renderer, font, "Game Over...");
	win_text.set_text(renderer, font, "Stage Complete!!");
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
	//Render game information
	score_text.render(renderer, { 16 , 0 });
	high_score_text.render(renderer, { ((float)window_width / 2) - (high_score_text.rect.w / 2), 0 });
	health_text.render(renderer, { window_width - health_text.rect.w - 16, 0 });

	//Win/Lose
	if (!player->sprite.visible)
		game_over_text.render(renderer, { ((float)window_width / 2) - (game_over_text.rect.w / 2), ((float)window_height / 2) - (game_over_text.rect.h / 2) });

	if(!boss->sprite.visible)
		win_text.render(renderer, { ((float)window_width / 2) - (win_text.rect.w / 2), ((float)window_height / 2) - (win_text.rect.h / 2)});
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
