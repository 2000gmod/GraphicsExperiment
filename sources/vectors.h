#ifndef VECTOR_H
#define VECTOR_H
#include <stdlib.h>

typedef struct vector2{
    int x;
    int y;
}vector2;

typedef struct vector3{
    int x;
    int y;
    int z;
}vector3;

void swapVector2(vector2* a, vector2* b);
void swapVector3(vector3* a, vector3* b);

void initVec2(vector2* in, int x, int y);

#endif