#pragma once
#include <raylib.h>
#include <iostream>

const int screenWidth = 1920;
const int screenHeight = 1080;

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
    int stats();
private:
    Color color;
    Vector2 ball;
    int radius;
    int speedX;
    int speedY;
};
