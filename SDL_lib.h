/**
 * @file SDLUtils.h
 * @author Guillaume Dindart (guillaume.dindart@etu.u-bordeaux.fr)
 * @author Enzo Cornaggia (enzo.cornaggia@etu.u-bordeaux.fr)
 * @brief Basic SDL helper function for lightup game
 * @version 0.2
 * @date 2022-03-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __SDLLIB_H__
#define __SDLLIB_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>


void SDL_initAndSetName(SDL_Renderer** pRenderer, SDL_Window** pWindow);

bool process(SDL_Window *win, SDL_Renderer *ren, SDL_Event *e);

#endif
