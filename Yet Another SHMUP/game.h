#pragma once

#include "core.h"
#include "ship.h"
#include "player.h"
#include "text.h"

#include <vector>

class Game : public Core
{
public:
	Game() = default;
	~Game() = default;

	void start() override;
	void tick(float delta) override;
	void render() override;
	
private:
	//Entities
	std::shared_ptr<Player> player;
	std::vector<std::shared_ptr<Ship>> enemies;

	//Gameplay
	Text score_text;
	Text high_score_text;
	int score = 0;
	int high_score = 0;
	void update_score_text();

	Text health_text;
	void update_health_text();
};

