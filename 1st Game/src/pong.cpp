#include "pong.h"
#include <raylib.h>
#include <iostream>
using namespace std;

Ball::Ball()
{
    x = 500;
    y = 250;
    speedX = 5;
    speedY = 5;
    radius = 15;
}

void Ball::Update(int b_x, int b_y)
{
    x += speedX;
    y += speedY;

    if (x + radius >= GetScreenWidth() || x - radius <= 0){
        speedX *= -1;
    }
    if (y + radius >= GetScreenHeight() || y - radius <= 0){
        speedY *= -1;
    }
}

void Ball::Draw()
{
    DrawCircle(x, y, radius, WHITE);
}

Barre::Barre()
{
    x = 10;
    y = 50;
    speedX = 3;
    speedY = 3;
    width = 10;
    height = 100;
    colore = Color{255, 255, 0, 255};
}

void Barre::Draw()
{
    DrawRectangleLines(x, y, width, height, colore);
}

void Barre::Move()
{
    if(IsKeyDown(KEY_DOWN))
    {
       y += speedY;
       if (y > GetScreenWidth())
       {
            y = screenWidth;
       }
    }
    else
    {
        if(IsKeyDown(KEY_UP))
        {
            y -= speedY;
            if (y < 0)
            {
                y = 0;
            }
        }
    }
}

