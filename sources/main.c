#include <SDL2/SDL.h>

#include <stdio.h>
#include <stdlib.h>

#include "rendering.h"
#include "vectors.h"
#include "shading.h"


SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* screen;

uint32_t* pixels = NULL;

int initSDL();

int main(){
    if(initSDL() > 0){
        return 0;
    }
    vector2 position;
    position.x = WIDTH/2;
    position.y = HEIGHT/2;
    vector2 origin;
    origin.x = WIDTH/2;
    origin.y = HEIGHT/2;

    while(1){

        SDL_PumpEvents();
        const Uint8 *state = SDL_GetKeyboardState(NULL);

        if(state[SDL_SCANCODE_ESCAPE]) break;

        if(state[SDL_SCANCODE_UP]){
            position.y -= 1;
        }
        if(state[SDL_SCANCODE_DOWN]){
            position.y += 1;
        }
        if(state[SDL_SCANCODE_LEFT]){
            position.x -= 1;
        }
        if(state[SDL_SCANCODE_RIGHT]){
            position.x += 1;
        }
        if(state[SDL_SCANCODE_R]){
            position.x = WIDTH/2;
            position.y = HEIGHT/2;
        }

        clearScreen(pixels);
        drawCircle(pixels, position, 20, RED);
        drawLine(pixels, position, origin, GREEN);
        drawRectangle(pixels, position, origin, WHITE);


        //screen update
        SDL_UpdateTexture(screen, NULL, pixels, WIDTH * sizeof(uint32_t));
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, screen, NULL, NULL);
        SDL_RenderPresent(renderer);

        SDL_Delay(5);
    }

    free(pixels);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

int initSDL(){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Error!\n");
        return 1;
    }

    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, SDL_WINDOW_SHOWN, &window, &renderer);
    screen = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
    pixels = (uint32_t*) malloc(WIDTH * HEIGHT * sizeof(uint32_t));

    if(window == NULL || screen == NULL || pixels == NULL){
        printf("Error 2!\n");
        return 2;
    }
    return 0;
}
