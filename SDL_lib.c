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

void SDL_initAndSetName(SDL_Renderer** pRenderer, SDL_Window** pWindow, env genv){
    // SDL2 init
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        SDL_printError(false);
    }
    // window init with name
    *pWindow = SDL_CreateWindow("CALCULATOR", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (*pWindow == NULL) {
        SDL_printError(true);
    }

    SDL_Surface* icon = IMG_Load("./img/calculette.jpg");
    genv->icon = icon;

    // Load font
    if (TTF_Init() == -1) {
        printf("[Error] TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
    genv->pFont = TTF_OpenFont("./font/04B_20__.ttf", 1000);
    if (!genv->pFont){
        ERROR("TTF_OpenFont: %s\n", "04B_20__.ttf");
    } 

    *pRenderer = SDL_CreateRenderer(*pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (*pRenderer == NULL) {
        SDL_printError(true);
    }
    SDL_SetWindowMinimumSize(*pWindow, 400, 300);
}

void draw_screen(SDL_Renderer* pRenderer, SDL_Window* pWindow){
    SDL_Rect rect;
    rect.x = 20;
    rect.y = 20;
    rect.w = 560;
    rect.h = 200;
    
    SDL_RenderFillRect(pRenderer, &rect);

    rect.x = rect.x + 5;
    rect.y = rect.y + 5;
    rect.h = rect.h - 10;
    rect.w = rect.w - 10;

    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(pRenderer, &rect);
}

void draw_touch_calc(SDL_Renderer* pRenderer, SDL_Window* pWindow, SDL_Texture* buttons_tex[], env genv, unsigned int numb_touch) {
    SDL_Rect rect;
    rect.x = 80;
    rect.y = 400;
    rect.w = TOUCH_SIZE;
    rect.h = TOUCH_SIZE;

    int count = 0; // index tab
    for (int i = 0; i < genv->nb_rows; i++){
        for (int y = 0; y < genv->nb_cols; y++){
            if (y == genv->nb_cols - 1){ // if last column

                // Draw white rectangle
                SDL_RenderFillRect(pRenderer, &rect); 

                // Draw text button
                rect.x = rect.x + 10;
                rect.y = rect.y + 10;
                rect.w = rect.w - 20;
                rect.h = rect.h - 20;
                SDL_RenderCopy(pRenderer, buttons_tex[count],NULL, &rect);
                rect.x = rect.x - 10;
                rect.y = rect.y - 10;
                rect.w = rect.w + 20;
                rect.h = rect.h + 20;

                rect.y = rect.y + TOUCH_SIZE + SPACE - 10;
                rect.x = 80;
            }
            else {
                SDL_RenderFillRect(pRenderer, &rect);
                rect.x = rect.x + 10;
                rect.y = rect.y + 10;
                rect.w = rect.w - 20;
                rect.h = rect.h - 20;
                SDL_RenderCopy(pRenderer, buttons_tex[count],NULL, &rect);
                rect.x = rect.x - 10;
                rect.y = rect.y - 10;
                rect.w = rect.w + 20;
                rect.h = rect.h + 20;
                rect.x = rect.x + TOUCH_SIZE + SPACE + 20;
            }
            count ++;
        }
    }
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

static SDL_Texture* text_at_texture(SDL_Renderer* pRenderer, char* text, TTF_Font* pFont, SDL_Color textColor) {
    SDL_Surface* surface;
    surface = TTF_RenderText_Solid(pFont, text, textColor);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(pRenderer, surface);

    SDL_FreeSurface(surface);

    return texture;
}

SDL_Texture** make_all_text_texture(SDL_Renderer* pRenderer, char* text[], int nbtext, env genv, SDL_Color textColor){
    SDL_Texture** tab = malloc(sizeof(SDL_Texture*) * nbtext);

    for (int i = 0; i < nbtext; i++) {
        SDL_Texture* texture = text_at_texture(pRenderer, text[i], genv->pFont, textColor);
        tab[i] = texture;
    }

    return tab;
}

void clean_texture_tab(SDL_Texture* tab[], int nbItem) {
    for (int i = 0; i < nbItem; i++) {
        SDL_DestroyTexture(tab[i]);
    }
    free(tab);
}

void draw_menu(SDL_Renderer* pRenderer, SDL_Window* pWindow, SDL_Texture* items[], int nbItem){
    int w, h;
    SDL_GetWindowSize(pWindow, &w, &h);

    int mx = w / 4;
    int my = h / 4;

    int item_height = (h / (nbItem / 3));
    int item_width = (w / 5);

    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
    SDL_RenderClear(pRenderer);

    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);

    SDL_Rect rItem;
    rItem.w = item_width;
    rItem.h = item_height;
    rItem.x = mx;
    rItem.y = my;

    for (int i = 0; i < nbItem; i++) {
        SDL_RenderFillRect(pRenderer, &rItem);

        SDL_Rect text;
        SDL_QueryTexture(items[i], NULL, NULL, &text.w, &text.h);
        text.w = rItem.w - SPACE * 6;
        text.x = rItem.x + SPACE * 3;
        text.h = rItem.h - SPACE * 2;
        text.y = rItem.y + SPACE;

        if (text.h < SPACE - SPACE / 3) {
            text.h = SPACE - SPACE / 3;
        }

        SDL_RenderCopy(pRenderer, items[i], NULL, &text);

        rItem.y += item_height + SPACE;
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
