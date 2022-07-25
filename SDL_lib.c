#include "SDL_lib.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "SDL_Menu.h"
#include "library/aux.h"
#include "library/op.h"

static void SDL_printError(bool init) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
    if (init) {
        SDL_Quit();
    }
    exit(EXIT_FAILURE);
}

void SDL_initAndSetName(SDL_Renderer** pRenderer, SDL_Window** pWindow){
    // SDL2 init
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_printError(false);
    }
    // window init with name
    *pWindow = SDL_CreateWindow("CALCULATOR", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800,
                                800, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (*pWindow == NULL) {
        SDL_printError(true);
    }

    *pRenderer = SDL_CreateRenderer(*pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);  //
    if (*pRenderer == NULL) {
        SDL_printError(true);
    }
    SDL_SetWindowMinimumSize(*pWindow, 400, 300);
}

bool process(SDL_Window *win, SDL_Renderer *ren, SDL_Event *e) {
  if (e->type == SDL_QUIT) {
    return false;
  }

  /* PUT YOUR CODE HERE TO PROCESS EVENTS */

  return true;
}