#include "sprite.h"

#include <SDL_image.h>
#include <cstdio>

Sprite::~Sprite()
{
    if(texture) 
        SDL_DestroyTexture(texture);
}

void Sprite::set_texture(SDL_Renderer* renderer, std::string file_path)
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

    rect.w = surface->w;
    rect.h = surface->h;
    center = { (rect.w / 2), (rect.h / 2) };

    SDL_FreeSurface(surface);
}

void Sprite::render(SDL_Renderer* renderer, SDL_FPoint position, float rotation)
{
    if (!texture || !visible)
        return;

    SDL_Rect srcrect = { 0, 0, (int)rect.w, (int)rect.h };

    rect.x = position.x;
    rect.y = position.y;

    SDL_RenderCopyExF(renderer, texture, &srcrect, &rect, rotation, &center, SDL_FLIP_NONE);
}
