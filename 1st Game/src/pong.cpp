#include "pong.h"
#include <raylib.h>
#include <iostream>
using namespace std;

int a = 0, score = 0;
int fontsize = 20;
const char difficulty1[] = "Difficulty = Easy";
const char difficulty2[] = "Difficulty = Medium";
const char difficulty3[] = "Difficulty = Hard";
const char difficulty4[] = "Difficulty = Impossible";
const char* p_res;

Ball::Ball()
{
    ball.x = screenWidth/2;
    ball.y = screenHeight/2;
    speedX = 5;
    speedY = 5;
    radius = 15;
    color = Color{255, 255, 0, 255};
}

void Ball::Update(Rectangle a, int X, int Y)
{
    ball.x += speedX;
    ball.y += speedY;
    p_res = TextFormat("Score = %d", score);

    if (ball.x + radius >= GetScreenWidth()){
        speedX *= -1;
    }
    if (ball.y + radius >= GetScreenHeight() || ball.y - radius <= 0){
        speedY *= -1;
    }
    if(CheckCollisionCircleRec(ball, radius, a))
    {
        if(score > 10)
        {
            speedX *= -1;
            score+=1;
        }
        else
        {
            speedX*=1.2;
            speedY*=1.2;
            speedX *= -1;
            score+=1;
        }
    }
    if(ball.x - radius <= 0)
    {
        ball.x = screenWidth/2;
        ball.y = screenHeight/2;
        speedX = 5;
        speedY = 5;
        score = 0;
    }
    if(score < 5)
    {
        DrawText(difficulty1, 30, screenHeight-20, fontsize, GREEN);
        DrawText(p_res, 220, screenHeight-20, fontsize, BEIGE);
        X = 5; Y = 5;
    }
    if(score < 10 && score >= 5)
    {
        DrawText(difficulty2, 30, screenHeight-20, fontsize, YELLOW);
        DrawText(p_res, 235, screenHeight-20, fontsize, BEIGE);
        X = 7; Y = 7;
    }
    if(score < 15 && score >= 10)
    {
        DrawText(difficulty3, 30, screenHeight-20, fontsize, RED);
        DrawText(p_res, 220, screenHeight-20, fontsize, BEIGE);
        X = 9; Y = 9;
    }
    if(score >= 15)
    {
        DrawText(difficulty4, 30, screenHeight-20, fontsize, MAGENTA);
        DrawText(p_res, 265, screenHeight-20, fontsize, BEIGE);
        X = 12; Y = 12;
    }
}

void Ball::Draw()
{
    DrawCircle(ball.x, ball.y, radius, color);
}

Paddle::Paddle()
{
    paddle.height = 100;
    paddle.width = 10;
    paddle.x = 10;
    paddle.y = screenHeight/2;
    speedX = 3.5;
    speedY = 3.5;
    color = Color{255, 255, 0, 255};
}

void Paddle::Draw()
{
    DrawRectangle(paddle.x, paddle.y, paddle.width, paddle.height, color);
}

void Paddle::Update()
{
    if(IsKeyDown(KEY_DOWN))
    {
        paddle.y += speedY;
        if(paddle.y >= (screenHeight - 100))
        {
            paddle.y = (screenHeight - 100);
        }
    }
    else
    {
        if(IsKeyDown(KEY_UP))
        {
            paddle.y -= speedY;
            if(paddle.y < 0)
            {
                paddle.y = 0;
            }
        }
    }
}

