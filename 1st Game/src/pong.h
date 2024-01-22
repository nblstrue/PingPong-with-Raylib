#pragma once
#include <raylib.h>

const int screenWidth = 800;
const int screenHeight = 800;

class Paddle
{
public:
    Paddle();
    void Update();
    void Draw();
    Rectangle paddle;

private:
    Color color;
    int speedX;
    int speedY;
};

class Ball
{
public:
    Ball();
    void Update(Rectangle a);
    void Draw();

private:
    Color color;
    Vector2 ball;
    int speedX;
    int speedY;
    int radius;
};
