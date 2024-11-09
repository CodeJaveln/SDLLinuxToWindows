#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <stdio.h>
#include "constants.h"
#include "game_structs.h"
#include "init.h"
#include "update.h"
#include "render.h"

int main(int argc, char *argv[]) {
    SDL_Window *window;
    SDL_Renderer *renderer;
    GameState gameState = {0};
    FILE *errorFile;

    int initReturn = SetupProcess(&gameState, &window, &renderer, &errorFile);
    if (initReturn != NO_ERROR) {
        Quit(window, renderer, errorFile);
        return initReturn;
    }

    gameState.RunGame = TRUE;
    while (gameState.RunGame) {
        Update(&gameState);
        Render(renderer, &gameState);
    }

    Quit(window, renderer, errorFile);
    return NO_ERROR;
}