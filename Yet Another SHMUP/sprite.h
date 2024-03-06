#pragma once

#include "types.h"
#include <SDL.h>
#include <string>

class Sprite
{
public:
	Sprite(SDL_Renderer* renderer, std::string file_path);
	~Sprite();

	void render(SDL_Renderer* renderer, vec2 position, float rotation);

	bool visible = true;
	vec2 size = { 0,0 };
	vec2 center = { 0,0 };

private:
	SDL_Texture* texture = NULL;
};