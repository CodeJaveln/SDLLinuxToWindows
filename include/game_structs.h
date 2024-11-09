#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "constants.h"

typedef struct {
    float X;
    float Y;
    float Width;
    float Height;
} Ball;

typedef struct {
    float X;
    float Y;
    int Active;
} Bullet;

typedef struct {
    int RunGame;
    int LastFrameTime;
    float DeltaTime;
    int KeyState[NUM_KEYS];
    Ball PlayerBall;
    Bullet Bullets[BULLETS_AMOUNT];
} GameState;

#endif