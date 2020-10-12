#include "pong.h"

void pongFrame(uint32_t* pixelBuffer, vector2* playerPos, vector2* enemyPos, vector2* ballPos, vector2* ballSpeed){
    int enemySpeed = 4;

    int barHeight = 160;
    int barWidth = 20;
    int ballSize= 20;

    vector2 playerCorner1, playerCorner2, enemyCorner1, enemyCorner2, ballCorner1, ballCorner2;
    initVec2(&playerCorner1, playerPos->x - barWidth/2, playerPos->y - barHeight/2);
    initVec2(&playerCorner2, playerPos->x + barWidth/2, playerPos->y + barHeight/2);
    initVec2(&enemyCorner1, enemyPos->x - barWidth/2, enemyPos->y - barHeight/2);
    initVec2(&enemyCorner2, enemyPos->x + barWidth/2, enemyPos->y + barHeight/2);

    initVec2(&ballCorner1, ballPos->x - ballSize/2, ballPos->y - ballSize/2);
    initVec2(&ballCorner2, ballPos->x + ballSize/2, ballPos->y + ballSize/2);
    

    if (ballPos->x < 0 || ballPos->x > WIDTH){
        initVec2(ballPos, WIDTH/2, HEIGHT/2);
        initVec2(ballSpeed, 5, -3);
    }
    if(ballPos->y <= 0 || ballPos->y >= HEIGHT){
        ballSpeed->y *= -1;
    }
    if(ballPos->y > enemyPos->y){
        enemyPos->y += enemySpeed;
    }
    else if(ballPos->y < enemyPos->y){
        enemyPos->y -= enemySpeed;
    }

    if(ballPos->x >= playerPos->x && (ballPos->y <= playerCorner2.y && ballPos->y >= playerCorner1.y)){
        ballSpeed->x *= -1;
        //ballSpeed->y *= -1;
    }
    if(ballPos->x <= enemyPos->x && (ballPos->y <= enemyCorner2.y && ballPos->y >= enemyCorner1.y)){
        ballSpeed->x *= -1;
        //ballSpeed->y *= -1;
    }
    ballPos->x += ballSpeed->x;
    ballPos->y += ballSpeed->y;

    drawFilledRect(pixelBuffer, enemyCorner1, enemyCorner2, WHITE);
    drawFilledRect(pixelBuffer, playerCorner1, playerCorner2, WHITE);
    drawFilledRect(pixelBuffer, ballCorner1, ballCorner2, WHITE);
    drawLine(pixelBuffer, *playerPos, *ballPos, GREEN);
    drawLine(pixelBuffer, *enemyPos, *ballPos, RED);
    return;
}