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

#include "env.h"

#define SPACE 20
#define SPRITE_SIZE 64
#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 600

#define WHITE \
    { 255, 255, 255, 255 }
#define BLACK \
    { 0, 0, 0, 255 }

typedef struct Env_s* env;

void SDL_initAndSetName(SDL_Renderer** pRenderer, SDL_Window** pWindow);

SDL_Texture** make_all_text_texture(SDL_Renderer* pRenderer, char* text[], int nbtext, env genv, SDL_Color textColor);

bool process(SDL_Window *win, SDL_Renderer *ren, SDL_Event *e);

/**
 * @brief Print an SDL2 error
 * @param pRenderer An SDL2 renderer
 * @param pWindow An SDL2 window
 */
void printDebug(SDL_Renderer* pRenderer, SDL_Window* pWindow);

env init_calc_environment();

void quit(env genv);




#endif
