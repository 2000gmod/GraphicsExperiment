#ifndef RENDERING_H
#define RENDERING_H

#include <SDL2/SDL.h>
#include <math.h>
#include "vectors.h"

#define WIDTH 700
#define HEIGHT 700

#define PI 3.1415

#define WHITE 0xFFFFFFFF
#define RED 0xFF0000FF
#define GREEN 0x00FF00FF
#define BLUE 0x0000FFFF


void clearScreen(uint32_t* pixelBuffer);
void drawPixel(uint32_t* pixelBuffer, vector2 pos, uint32_t colour);

void drawCircle(uint32_t* pixelBuffer, vector2 pos, int radius, uint32_t colour);
void drawLine(uint32_t* pixelBuffer, vector2 p1, vector2 p2, uint32_t colour);

void drawRectangle(uint32_t* pixelBuffer, vector2 p1, vector2 p2, uint32_t colour);
void drawQuad(uint32_t* pixelBuffer, vector2 p1, vector2 p2, vector2 p3, vector2 p4, uint32_t colour);

#endif