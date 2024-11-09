#include "update.h"

static void ProcessInput(GameState *gameState) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                gameState->RunGame = FALSE;
                break;
            case SDL_KEYDOWN:
                if (event.key.repeat == 0) {
                    gameState->KeyState[event.key.keysym.scancode] = TRUE;
                }
                break;
            case SDL_KEYUP:
                gameState->KeyState[event.key.keysym.scancode] = FALSE;
                break;
        }
    }
}

static void FireBullet(GameState *gameState) {
    for (int i = 0; i < BULLETS_AMOUNT; i++) {
        if (!gameState->Bullets[i].Active) {
        }
    }
}

void Update(GameState *gameState) {
    ProcessInput(gameState);

    if (gameState->KeyState[SDL_SCANCODE_ESCAPE]) {
        gameState->RunGame = FALSE;
        return;
    }

    int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - gameState->LastFrameTime);

    if (timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME) {
        SDL_Delay(timeToWait);
    }

    gameState->DeltaTime = (SDL_GetTicks() - gameState->LastFrameTime) / 1000.0f;

    if (gameState->KeyState[SDL_SCANCODE_A]) {
        gameState->PlayerBall.X -= 70.0f * gameState->DeltaTime;
    }
    if (gameState->KeyState[SDL_SCANCODE_D]) {
        gameState->PlayerBall.X += 70.0f * gameState->DeltaTime;
    }
    if (gameState->KeyState[SDL_SCANCODE_SPACE]) {

    }

    gameState->LastFrameTime = SDL_GetTicks();
}