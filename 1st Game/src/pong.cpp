#include "pong.h"
#include <raylib.h>
#include <iostream>
using namespace std;

Ball::Ball()
{
    ball.x = 425;
    ball.y = 425;
    speedX = 5;
    speedY = 5;
    radius = 15;
    color = Color{255, 255, 255, 255};
}

void Ball::Update(Rectangle a)
{
    ball.x += speedX;
    ball.y += speedY;

    if (ball.x + radius >= GetScreenWidth() || ball.x - radius <= 0){
        speedX *= -1;
    }
    if (ball.y + radius >= GetScreenHeight() || ball.y - radius <= 0){
        speedY *= -1;
    }
    if(CheckCollisionCircleRec(ball, radius, a))
    {
        speedX *= -1;
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
    paddle.y = 400;
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
        if(paddle.y >= 700)
        {
            paddle.y = 700;
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

