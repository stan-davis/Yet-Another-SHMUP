#pragma once

#include "sprite.h"
#include "health.h"

#include <memory>
#include <vector>

class Entity
{
public:
	Entity() = default;
	~Entity() = default;

	virtual void tick(float delta);

	//Data
	SDL_FPoint position = { 0,0 };
	SDL_FPoint velocity = { 0,0 };
	float rotation = 0;
	float speed = 0;

	//Components
	Sprite sprite;
	Health health;
	std::vector<std::shared_ptr<Entity>> children;
};

