#include "input.h"
#include <memory>

Input::Input()
{
	keyboard_state = SDL_GetKeyboardState(&key_length);
	prev_key_state = new uint8_t[key_length];
	memcpy(prev_key_state, keyboard_state, key_length);
}

Input::~Input()
{
	delete[] prev_key_state;
	prev_key_state = nullptr;
}

void Input::tick()
{
	memcpy(prev_key_state, keyboard_state, key_length);
}

bool Input::is_key_pressed(SDL_Scancode scancode)
{
	return !prev_key_state[scancode] && keyboard_state[scancode];
}

bool Input::is_key_held(SDL_Scancode scancode)
{
	return keyboard_state[scancode];
}

bool Input::is_key_released(SDL_Scancode scancode)
{
	return prev_key_state[scancode] && !keyboard_state[scancode];
}
