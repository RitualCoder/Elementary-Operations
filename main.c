#include <SDL.h>
#include <SDL_image.h>  // required to load transparent texture from PNG
#include <SDL_ttf.h>    // required to use TTF fonts
#include <stdbool.h>
#include <stdio.h>

#include "SDL_Menu.h"
#include "SDL_lib.h"

int main(int argc, char* argv[]){
    SDL_Window* pWindow = NULL;
    SDL_Renderer* pRenderer = NULL;
    SDL_Event e;

    // double fps = 0;
    bool main_loop_run = true;

    init(&pRenderer, &pWindow);

    while (main_loop_run){
        while (SDL_PollEvent(&e)) {
            /* process your events */
            main_loop_run = process(pWindow, pRenderer, &e);

            if (!main_loop_run){
                break;
            }
        }
        SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
        SDL_RenderClear(pRenderer);

        SDL_RenderPresent(pRenderer);
        SDL_Delay(50);
    }

    SDL_end(pRenderer, pWindow);
    return EXIT_SUCCESS;
}