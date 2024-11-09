#include "init.h"

static int InitializeSDL(SDL_Window **window, SDL_Renderer **renderer) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error initializing SDL, SDL_GetError: %s\n", SDL_GetError());
        return ERROR;
    }

    *window = SDL_CreateWindow(
        NULL, 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_BORDERLESS 
    );
    if (!*window) {
        fprintf(stderr, "Error initializing SDL Window, SDL_GetError: %s\n", SDL_GetError());
        return ERROR;
    }

    *renderer = SDL_CreateRenderer(
        *window,
        -1,
        0
    );
    if (!*renderer) {
        fprintf(stderr, "Error initializing SDL Renderer, SDL_GetError: %s\n", SDL_GetError());
        return ERROR;
    }

    return NO_ERROR;
}

static void DeinitializeSDL(SDL_Window *window, SDL_Renderer *renderer) {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
    else {
        fprintf(stderr, "WARNING: renderer was destroyed or didn't exist before deinitialization!");
    }

    if (window) {
        SDL_DestroyWindow(window);
    }
    else {
        fprintf(stderr, "WARNING: window was destroyed or didn't exist before deinitialization!");
    }

    SDL_Quit();
}

int SetupProcess(GameState *gameState, SDL_Window **window, SDL_Renderer **renderer, FILE **errorFile) {
    *errorFile = freopen("./bin/error.txt", "w", stderr);
    if (!*errorFile) {
        perror("Failed to redirect stderr, exiting SetupProcess!");
        return FILE_ERROR;
    }

    gameState->RunGame = 0;
    gameState->LastFrameTime = 0;
    gameState->DeltaTime = 0.0f;
    gameState->PlayerBall.X = 200.0f;
    gameState->PlayerBall.Y = 300.0f;
    gameState->PlayerBall.Width = 15.0f;
    gameState->PlayerBall.Height = 15.0f;

    for (int i = 0; i < MAX_BULLETS_AMOUNT; i++) {
        gameState->Bullets[i].Active = FALSE;
    }

    return InitializeSDL(window, renderer);
}

void Quit(SDL_Window *window, SDL_Renderer *renderer, FILE *errorFile) {
    DeinitializeSDL(window, renderer);

    if (errorFile) {
        fclose(errorFile);
    }
}