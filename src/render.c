#include "render.h"

void Render(SDL_Renderer *renderer, GameState *gameState) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_FRect playerRect = {
        gameState->PlayerBall.X,
        gameState->PlayerBall.Y,
        gameState->PlayerBall.Width,
        gameState->PlayerBall.Height,
    };

    SDL_RenderFillRectF(renderer, &playerRect);

    for (int i = 0; i < MAX_BULLETS_AMOUNT; i++) {
        if (!gameState->Bullets[i].Active) {
            continue;
        }

        SDL_FRect bulletRect = {
            gameState->Bullets[i].X,
            gameState->Bullets[i].Y,
            BULLET_WIDTH,
            BULLET_HEIGHT
        };

        SDL_RenderFillRectF(renderer, &bulletRect);
    }

    SDL_RenderPresent(renderer);
}