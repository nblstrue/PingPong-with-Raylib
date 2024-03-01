#pragma once
#include <raylib.h>
#include <iostream>

int screenWidth = 1900;
int screenHeight = 900;

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
