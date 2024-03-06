#include "sprite.h"

#include <SDL_image.h>
#include <cstdio>

Sprite::Sprite(SDL_Renderer* renderer, std::string file_path)
{
    SDL_Surface* surface = IMG_Load(file_path.c_str());

    if (!surface)
    {
        printf("Error: Failed to create surface\nSDL Error: '%s'\n", SDL_GetError());
        return;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);

    if (!texture)
    {
        printf("Error: Failed to create texture\nSDL Error: '%s'\n", SDL_GetError());
        return;
    }

    size.x = surface->w;
    size.y = surface->h;
    center = { (size.x / 2), (size.y / 2) };

    SDL_FreeSurface(surface);
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(texture);
}

void Sprite::render(SDL_Renderer* renderer, vec2 position, float rotation)
{
    if (!texture || !visible)
        return;

    SDL_Rect srcrect = { 0, 0, (int)size.x, (int)size.y };
    SDL_Rect dstrect = { (int)position.x, (int)position.y, (int)size.x, (int)size.y };
    SDL_Point p_center = { (int)center.x, (int)center.y };

    SDL_RenderCopyEx(renderer, texture, &srcrect, &dstrect, rotation, &p_center, SDL_FLIP_NONE);
}
