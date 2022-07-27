#include "SDL_lib.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "SDL_Menu.h"
#include "library/aux.h"
#include "library/op.h"
#include "env.h"

static void SDL_printError(bool init) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
    if (init) {
        SDL_Quit();
    }
    exit(EXIT_FAILURE);
}

void SDL_initAndSetName(SDL_Renderer** pRenderer, SDL_Window** pWindow){
    // SDL2 init
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        SDL_printError(false);
    }
    // window init with name
    *pWindow = SDL_CreateWindow("CALCULATOR", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (*pWindow == NULL) {
        SDL_printError(true);
    }

    *pRenderer = SDL_CreateRenderer(*pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (*pRenderer == NULL) {
        SDL_printError(true);
    }
    SDL_SetWindowMinimumSize(*pWindow, 400, 300);
}

env init_calc_environment() {
    env genv = malloc(sizeof(struct Env_s));
    genv->nb_cols = 4;
    genv->nb_rows = 3;
    genv->window_height = WINDOW_HEIGHT;
    genv->windows_width = WINDOW_WIDTH;
    return genv;
}

//SDL_Texture** make_all_text_texture(SDL_Renderer* pRenderer, char* text[], int nbtext, env genv, SDL_Color textColor){




void printDebug(SDL_Renderer* pRenderer, SDL_Window* pWindow) {
    int videoDriverIndex = SDL_GetNumVideoDrivers();
    SDL_Log("Video driver: %d -> %s\n", videoDriverIndex, SDL_GetVideoDriver(videoDriverIndex));
    SDL_RendererInfo info;
    if (SDL_GetRendererInfo(pRenderer, &info) >= 0) {
        SDL_Log("Renderer name: %s\n", info.name);
        int width, height;
        SDL_GetWindowSize(pWindow, &width, &height);
        SDL_Log("Window size %dx%d\n", width, height);
    }
}



bool process(SDL_Window *win, SDL_Renderer *ren, SDL_Event *e) {
    if (e->type == SDL_QUIT) {
        return false;
    }
    return true;
}

void quit(env genv){
    free(genv);
}
