#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/time.h>

#include "SDL_Menu.h"
#include "library/aux.h"
#include "library/op.h"
#include "SDL_lib.h"
#include "env.h"


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


void SDL_end(SDL_Renderer* pRenderer, SDL_Window* pWindow) {
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
}