/**
 * @file SDLMenu.h
 * @author Guillaume Dindart (guillaume.dindart@etu.u-bordeaux.fr)
 * @author Enzo Cornaggia (enzo.cornaggia@etu.u-bordeaux.fr)
 * @brief
 * @version 0.1
 * @date 2022-03-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __SDLMENU_H__
#define __SDLMENU_H__

#include <SDL2/SDL.h>
#include <stdbool.h>


/**
 * @brief Destroy pRenderer and pWindow
 *
 * @param pRenderer An SDL2 renderer
 * @param pWindow An SDL2 window
 */
void SDL_end(SDL_Renderer* pRenderer, SDL_Window* pWindow);

#endif
