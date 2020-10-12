#ifndef PONG_H
#define PONG_H
#include "vectors.h"
#include "rendering.h"

void pongFrame(uint32_t* pixelBuffer, vector2* playerPos, vector2* enemyPos, vector2* ballPos, vector2* ballSpeed);

#endif