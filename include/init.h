#ifndef INIT_H
#define INIT_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include "constants.h"
#include "game_structs.h"

/**
 * @returns
 * - `NO_ERROR` (0) if no errors occur.
 * - `ERROR` (-1) if SDL couldn't initialize.
 * - `FILE_ERROR` (-2) if it couldn't open the error stream, makes an early return.
 */
int SetupProcess(GameState *gameState, SDL_Window **window, SDL_Renderer **renderer, FILE **errorFile);

void Quit(SDL_Window *window, SDL_Renderer *renderer, FILE *errorFile);

#endif