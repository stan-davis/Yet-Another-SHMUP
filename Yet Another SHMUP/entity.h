#pragma once

#include "sprite.h"
#include "aabb.h"
#include "health.h"

#include <memory>

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
	int speed = 0;

	//Components
	std::unique_ptr<Sprite> sprite;
	std::unique_ptr<AABB> aabb;
	std::unique_ptr<Health> health;
};

