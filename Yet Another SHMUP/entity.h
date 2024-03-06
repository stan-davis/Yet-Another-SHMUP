#pragma once

#include "types.h"
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
	vec2 position = { 0,0 };
	vec2 velocity = { 0,0 };
	float rotation = 0;
	int speed = 0;

	//Components
	std::unique_ptr<Sprite> sprite;
	std::unique_ptr<AABB> aabb;
	std::unique_ptr<Health> health;
};

