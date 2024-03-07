#include "core.h"

#include "ship.h"
#include <SDL_image.h>
#include <cstdio>

int Core::run(int _window_width, int _window_height, int _frame_rate)
{
    window_width = _window_width;
    window_height = _window_height;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Error: SDL failed to initialize.\n '%s'\n", SDL_GetError());
        return 1;
    }

    if (SDL_CreateWindowAndRenderer(window_width, window_height, 0, &window, &renderer) != 0)
    {
        printf("Error: Failed to create window or renderer.\n '%s'\n", SDL_GetError());
        return 1;
    }

    SDL_SetWindowTitle(window, "Yet Another SHMUP");

    int img_flags = IMG_INIT_PNG;
    if (IMG_Init(img_flags) != img_flags)
    {
        printf("Error: IMG failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() != 0)
    {
        printf("Error: TTF failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    font = TTF_OpenFont("assets/MMXSNES.ttf", 64);

    time.set_target_frame_rate(_frame_rate);

    start();

    while (is_running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                is_running = false;
                break;
            default:
                break;
            }
        }

        time.tick();
        SDL_SetRenderDrawColor(renderer, 2, 8, 15, 255); //Dark
        SDL_RenderClear(renderer);

        //Tick core
        tick(time.get_delta_time());

        //Tick entities
        for (auto& entity : entities)
        {
            entity->tick(time.get_delta_time());

            for (auto& child : entity->children)
                child->tick(time.get_delta_time());
        }

        //Render entities
        for (auto& entity : entities)
        {
            entity->sprite.render(renderer, entity->position, entity->rotation);
            draw_debug_rect(entity->rect);

            for (auto& child : entity->children)
            {
                child->sprite.render(renderer, child->position, child->rotation);
                draw_debug_rect(child->rect);
            }
        }

        //Render (UI)
        render();

        SDL_RenderPresent(renderer);

        time.late_tick();
    }

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

    return 0;
}

void Core::draw_debug_rect(SDL_FRect& rect)
{
    if (!is_debug)
        return;

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawRectF(renderer, &rect);
}
