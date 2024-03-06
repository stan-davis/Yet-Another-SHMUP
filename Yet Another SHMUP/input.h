#pragma once

#include <SDL.h>
#include "ship.h"

class Input
{
public:
    Input();
    ~Input();

    void tick();

    bool is_key_pressed(SDL_Scancode scancode);
    bool is_key_held(SDL_Scancode scancode);
    bool is_key_released(SDL_Scancode scancode);

private:
    const uint8_t* keyboard_state;
    uint8_t* prev_key_state;
    int key_length;
};