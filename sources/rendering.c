#include "rendering.h"

void clearScreen(uint32_t* pixelBuffer){
    for(int k = 0; k <= WIDTH * HEIGHT; k++){
        pixelBuffer[k] = 0;
    }
}

void drawPixel(uint32_t* pixelBuffer, vector2 pos, uint32_t colour){
    if(pos.x < 0 || pos.x > WIDTH || pos.y < 0 || pos.y > HEIGHT){
        return;
    }
    pixelBuffer[pos.y*WIDTH + pos.x] = colour;
    return;
}

void drawCircle(uint32_t* pixelBuffer, vector2 pos, int radius, uint32_t colour){
    vector2 pixel;
    for(float t = 0.0f; t < 2*PI; t += 0.01f){
        pixel.x = (int)radius*cos(t) + pos.x;
        pixel.y = (int)radius*sin(t) + pos.y;
        drawPixel(pixelBuffer, pixel, colour);
    }
    return;
}

void drawLine(uint32_t* pixelBuffer, vector2 p1, vector2 p2, uint32_t colour){
    vector2 drawing;
    if(p1.x > p2.x)swapVector2(&p1, &p2);

    if(p1.x == p2.x){
        drawing.x = p1.x;
        if(p1.y > p2.y){
            int temp = p2.y;
            p2.y = p1.y;
            p1.y = temp;
        }
        for(int k = p1.y; k<= p2.y; k++){
            drawing.y = k;
            drawPixel(pixelBuffer, drawing, colour);
        }
        return;
    }
    float slope = (float) (p2.y - p1.y)/(p2.x - p1.x);
    slope = (float) (p2.y - p1.y)/(p2.x - p1.x);

    float axisCol = (float) p1.y - slope*p1.x;
    for(int k = p1.x; k < p2.x; k++){
        drawing.x = k;
        drawing.y = k*slope + axisCol;
        for(int j = 0; j <= fabs(slope); j++){
            drawPixel(pixelBuffer, drawing, colour);
            if(slope < 0) drawing.y -= 1;
            else drawing.y +=1;
        }
    }
    return;
}

void drawRectangle(uint32_t* pixelBuffer, vector2 p1, vector2 p2, uint32_t colour){
    vector2 p3;
    vector2 p4;

    p3.x = p2.x;
    p3.y = p1.y;
    
    p4.x = p1.x;
    p4.y = p2.y;

    drawLine(pixelBuffer, p1, p3, colour);
    drawLine(pixelBuffer, p1, p4, colour);

    drawLine(pixelBuffer, p2, p3, colour);
    drawLine(pixelBuffer, p2, p4, colour);
    return;
}

void drawQuad(uint32_t* pixelBuffer, vector2 p1, vector2 p2, vector2 p3, vector2 p4, uint32_t colour){
    drawLine(pixelBuffer, p1, p3, colour);
    drawLine(pixelBuffer, p1, p4, colour);

    drawLine(pixelBuffer, p2, p3, colour);
    drawLine(pixelBuffer, p2, p4, colour);
    return;
}

void drawFilledRect(uint32_t* pixelBuffer, vector2 p1, vector2 p2, uint32_t colour){
    if(p1.x == p2.x || p1.y == p2.y) return;
    if(p1.y < p2.y) swapVector2(&p1, &p2);

    vector2 draw1, draw2;
    *(&draw1) = *(&p1);
    draw2.y = p1.y;
    draw2.x = p2.x;

    for(int k = 0; k < p1.y - p2.y; k++){
        draw1.y += 1;
        draw2.y += 1;
        drawLine(pixelBuffer, draw1, draw2, colour);
    }
    return;
}
/*
void drawGrid(uint32_t* pixelBuffer, uint32_t colorThick, uint32_t colorThin, int thickLines, int thinLinesPerThick){
    vector2 horLeft, horRight, verUp, verDown;
    float thickSpacing = (float) WIDTH / thickLines; 
    for(int k = 0; k < thickLines/2; k++){

    }
}
*/