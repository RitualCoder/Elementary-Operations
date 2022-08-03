/**
 * @file env.h
 * @author Enzo Cornaggia (enzo.cornaggia@etu.u-bordeaux.fr)
 * @brief Environement struct for calculator
 * @date 2022-07-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __ENV_H__
#define __ENV_H__
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <sys/time.h>

struct Env_s {
    int windows_width, window_height;
    int mouse_x, mouse_y;
    int case_x, case_y;
    int nb_rows, nb_cols;
    int sprite_size;

    SDL_Surface* icon;

    TTF_Font* pFont;
};

typedef struct Env_s* Env_s;

#endif