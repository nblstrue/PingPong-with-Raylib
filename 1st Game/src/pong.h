#pragma once
#include <raylib.h>

const int screenWidth = 1700;
const int screenHeight = 700;

class Paddle
{
public:
    Paddle();
    void Update();
    void Draw();
    Color color;
    Rectangle paddle;
    int speedX;
    int speedY;
};

class Ball
{
public:
    Ball();
    void Update(Rectangle a);
    void Draw();
    Color color;
    Vector2 ball;
    int radius;
    int speedX;
    int speedY;
};
