#pragma once

#include "core.h"
#include "ship.h"
#include "player.h"

#include <vector>

class Game : public Core
{
public:
	Game() = default;
	~Game() = default;

	void start() override;
	void tick(float delta) override;
	
	std::shared_ptr<Player> player;
	std::vector<std::shared_ptr<Ship>> enemies;
};

