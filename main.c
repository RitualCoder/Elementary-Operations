#include <SDL.h>
#include <SDL_image.h>  // required to load transparent texture from PNG
#include <SDL_ttf.h>    // required to use TTF fonts
#include <stdbool.h>
#include <stdio.h>

#include "env.h"
#include "SDL_Menu.h"
#include "SDL_lib.h"


int main(int argc, char* argv[]){
    SDL_Window* pWindow = NULL;
    SDL_Renderer* pRenderer = NULL;
    SDL_Event e;

    // init calculator environment
    env genv = init_calc_environment();

    // double fps = 0;
    bool main_loop_run = true;

    init(&pRenderer, &pWindow);

    // Start render, create all buttons 

    char* buttons[] = {"7", "8", "9", "-", "4", "5", "6", "x", "1", "2", "3", "/"};
    SDL_Color black = BLACK;

    // SDL_Texture** buttons_tex = make_all_text_texture(pRenderer, buttons, 12, genv, black);

    while (main_loop_run){
        while (SDL_PollEvent(&e)) {
            // process events
            main_loop_run = process(pWindow, pRenderer, &e);

            if (!main_loop_run){
                break;
            }
        }
        SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
        SDL_RenderClear(pRenderer);

        SDL_RenderPresent(pRenderer);
        SDL_Delay(100);
    }

    quit(genv);
    SDL_end(pRenderer, pWindow);

    return EXIT_SUCCESS;
}