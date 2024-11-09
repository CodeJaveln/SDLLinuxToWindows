#include "render.h"

void Render(SDL_Renderer *renderer, GameState *gameState) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_FRect playerRect = {
        gameState->PlayerBall.X,
        gameState->PlayerBall.Y,
        gameState->PlayerBall.Width,
        gameState->PlayerBall.Height,
    };

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRectF(renderer, &playerRect);

    SDL_RenderPresent(renderer);
}