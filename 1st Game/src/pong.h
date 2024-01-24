#pragma once
#include <raylib.h>

const int screenWidth = 1800;
const int screenHeight = 305;

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
    void Update(Rectangle a, int X, int Y);
    void Draw();
    Color color;
    Vector2 ball;
    int radius;
    int speedX;
    int speedY;
};
