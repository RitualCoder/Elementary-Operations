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

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 600

#define TOUCH_SIZE 80
#define SPACE 20
#define WIDTH_BIG_CELL 360

#define WHITE \
    { 255, 255, 255, 255 }
#define BLACK \
    { 0, 0, 0, 255 }

#define ERROR(STR, ...) do { fprintf(stderr, STR, ##__VA_ARGS__); exit(EXIT_FAILURE); } while(0)


typedef struct Env_s* env;

void SDL_initAndSetName(SDL_Renderer** pRenderer, SDL_Window** pWindow, env genv);

SDL_Texture** make_all_text_texture(SDL_Renderer* pRenderer, char* text[], int nbtext, env genv, SDL_Color textColor);

bool process(SDL_Window *win, SDL_Renderer *ren, SDL_Event *e, bool *FPS);

void printDebug(SDL_Renderer* pRenderer, SDL_Window* pWindow);

void draw_fps(SDL_Renderer* pRenderer, SDL_Window* pWindow, env genv, char *elapsed);

void draw_screen(SDL_Renderer* pRenderer, SDL_Window* pWindow);

void draw_touch_calc(SDL_Renderer* pRenderer, SDL_Window* pWindow, SDL_Texture* s_buttons_tex[], env genv);

env init_calc_environment();

void clean_texture_tab(SDL_Texture* tab[], int nbItem);

void draw_menu(SDL_Renderer* pRenderer, SDL_Window* pWindow, SDL_Texture* items[], int nbItem);


void quit(env genv);




#endif
