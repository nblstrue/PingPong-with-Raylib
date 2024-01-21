#pragma once
#include <raylib.h>

const int screenWidth = 1000;
const int screenHeight = 500;

class Barre
{
public:
    Barre();
    void Move();
    void Draw();
    int x;
    int y;
    int score;

private:
    int speedX;
    int speedY;
    int width;
    int height;
    Color colore;
};

class Ball
{
public:
    Ball();
    void Update(int b_x, int b_y);
    void Draw();
    int speedX;
    int speedY;

private:
    int x;
    int y;
    int radius;
};
