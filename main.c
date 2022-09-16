#include <SDL.h>
#include <SDL_image.h>  // required to load transparent texture from PNG
#include <SDL_ttf.h>    // required to use TTF fonts
#include <stdbool.h>
#include <stdio.h>

#include "env.h"
#include "SDL_Menu.h"
#include "SDL_lib.h"
#include "./library/aux.h"


int main(int argc, char* argv[]){
    SDL_Window* pWindow = NULL;
    SDL_Renderer* pRenderer = NULL;
    SDL_Event e;

    // init calculator environment
    env genv = init_calc_environment();
    op var = init_(100);

    // FPS
    int FPS = 60;
    int frameDelay = 1000/FPS;
    Uint32 frameStart;
    int frameTime;
    bool show_fps = false;

    bool main_loop_run = true;

    init(&pRenderer, &pWindow, genv);

    SDL_SetWindowIcon(pWindow, genv->icon);

    SDL_FreeSurface(genv->icon);

    // Start render, create all buttons 

    char* buttons[] = {"C", "(", ")", "+", "7", "8", "9", "-", "4", "5", "6", "x", "1", "2", "3", "/", "0", ".", "=", "^"};
    SDL_Color black = BLACK;

    SDL_Texture** buttons_tex = make_all_text_texture(pRenderer, buttons, 20, genv, black);

    
    while (main_loop_run){
        Uint64 start = SDL_GetPerformanceCounter();
        frameStart = SDL_GetTicks();

        
	    
        while (SDL_PollEvent(&e)) {
            // process events
            main_loop_run = process(pWindow, pRenderer, &e, &show_fps, var);

            if (!main_loop_run){
                break;
            }
        }
        SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
        SDL_RenderClear(pRenderer);

        // Draw all graphics
        SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
        draw_touch_calc(pRenderer,pWindow, buttons_tex, genv);
        draw_screen(pRenderer, pWindow);

        // FPS LIMIT
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }

        // SHOW FPS
        Uint64 end = SDL_GetPerformanceCounter();
        char elapsed[8];
        int fps = 1/((end - start) / (float)SDL_GetPerformanceFrequency());
        int_to_char(fps, elapsed);
        if (show_fps){
            draw_fps(pRenderer, pWindow, genv, elapsed);
        }

        SDL_RenderPresent(pRenderer);
        SDL_Delay(100);
    }

    clean_texture_tab(buttons_tex, 20);

    quit(genv);
    TTF_Quit();
    SDL_end(pRenderer, pWindow);

    return EXIT_SUCCESS;
}