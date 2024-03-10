#pragma once
#include <raylib.h>
#include <iostream>

const int screenWidth = 1900;
const int screenHeight = 1000;

class Paddle
{
    public:
        Paddle();
        void Update();
        void Draw();
        Rectangle paddle;
    private:
        Color color;
        int speedX, speedY;
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
        void error();
        void reLoading();
        int radius, speedX, speedY;
};
