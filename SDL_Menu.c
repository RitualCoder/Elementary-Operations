#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/time.h>

#include "library/aux.h"
#include "library/op.h"

bool init(SDL_Renderer** pRenderer, SDL_Window** pWindow){
    // event init
    bool run = true;

    // window init
    SDL_initAndSetName(pRenderer, pWindow);

    // mouse
    SDL_PumpEvents();

    // Some debug info on Video Mode
    printDebug(*pRenderer, *pWindow);

    return run;
}


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

void SDL_end(SDL_Renderer* pRenderer, SDL_Window* pWindow) {
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
}