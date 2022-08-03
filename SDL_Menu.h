/**
 * @file SDLMenu.h
 * @author Enzo Cornaggia (enzo.cornaggia@icloud.com)
 * @brief
 * @version 0.1
 * @date 2022-07-25
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __SDLMENU_H__
#define __SDLMENU_H__


#include <SDL2/SDL.h>
#include <stdbool.h>

#include "env.h"

typedef struct Env_s* env;

/**
 * @brief Init base of SDL2 and game environement
 * @param pRenderer An SDL2 renderer
 * @param pWindow An SDL2 Window
 * @return True All good
 * @return False problem append
 */
bool init(SDL_Renderer** pRenderer, SDL_Window** pWindow, env genv);

/**
 * @brief Destroy pRenderer and pWindow
 * @param pRenderer An SDL2 renderer
 * @param pWindow An SDL2 window
 */
void SDL_end(SDL_Renderer* pRenderer, SDL_Window* pWindow);

#endif
