#include <raylib.h>
#include "pong.h"

int main()
{
    Color black = Color{0, 0, 0, 255};
    Ball ball = Ball();
    Paddle paddle = Paddle();

    InitWindow(screenWidth, screenHeight, "Pong with Raylib, by n3izvn");
    SetTargetFPS(90);
    HideCursor();
    InitAudioDevice();

    Music hype = LoadMusicStream("src/aud/ULTRA_NECROZMA.mp3");
    PlayMusicStream(hype);  

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(black);
        DrawFPS(30, 0);
        UpdateMusicStream(hype);
        ball.Update(paddle.paddle, paddle.speedX, paddle.speedY);
        ball.Draw();
        paddle.Update();
        paddle.Draw();
        EndDrawing();
    }

    UnloadMusicStream(hype);
    CloseWindow();
    CloseAudioDevice();
    return 0;
}