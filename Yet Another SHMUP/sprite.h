#pragma once

#include <SDL.h>
#include <string>

class Sprite
{
public:
	Sprite(SDL_Renderer* renderer, std::string file_path);
	~Sprite();

	void render(SDL_Renderer* renderer, SDL_FPoint position, float rotation);

	bool visible = true;
	SDL_FPoint size = { 0,0 };
	SDL_FPoint center = { 0,0 };

private:
	SDL_Texture* texture = NULL;
};