#include "vectors.h"

void swapVector2(vector2* a, vector2* b){
    vector2* temp = (vector2*) malloc(sizeof(vector2));
    *temp = *a;
    *a = *b;
    *b = *temp;
    free(temp);
    return;
}

void swapVector3(vector3* a, vector3* b){
    vector3* temp = (vector3*) malloc(sizeof(vector3));
    *temp = *a;
    *a = *b;
    *b = *temp;
    free(temp);
    return;
}

void initVec2(vector2* in, int x, int y){
    in->x = x;
    in->y = y;
    return;
}

void vec2CopyAToB(vector2* a, vector2* b){
    *b = *a;
    return;
}