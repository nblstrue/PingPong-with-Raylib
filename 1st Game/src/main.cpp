#include <raylib.h>
#include "pong.h"

int main()
{
    Color black = Color{0, 0, 0, 255};

    Ball ball = Ball();
    Paddle paddle = Paddle();

    InitWindow(screenWidth, screenHeight, "Pong with Raylib, by n3izvn");
    SetTargetFPS(60);
    ShowCursor();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(black);
        DrawFPS(screenWidth-10, screenHeight-10);
        ball.Update(paddle.paddle);
        ball.Draw();
        paddle.Update();
        paddle.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}