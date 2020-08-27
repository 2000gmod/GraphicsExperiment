#ifndef SHADING_H
#define SHADING_H

#include "rendering.h"

#include <SDL2/SDL.h>
#include <math.h>
#include "vectors.h"

void shadeBlur(uint32_t* pixelBuffer, int radius);

#endif