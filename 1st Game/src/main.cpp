#include <raylib.h>
#include "pong.h"

int main()
{
    Color black = Color{0, 0, 0, 255};
    Ball ball = Ball();
    Paddle paddle = Paddle();
    Music music;

    InitWindow(screenWidth, screenHeight, "Stellar Ping Pong 1.2 - Try to hit a score of 40 to win the game !!");
    SetTargetFPS(60);
    HideCursor();
    InitAudioDevice();
    music = LoadMusicStream("src/aud/ULTRA_NECROZMA.mp3");
    PlayMusicStream(music); 

    while (!WindowShouldClose())
    {
        BeginDrawing();
        UpdateMusicStream(music);

        if(!IsMusicStreamPlaying(music))
        {
            music = LoadMusicStream("src/aud/ULTRA_NECROZMA.mp3");
            PlayMusicStream(music);
        }

        ClearBackground(black);
        DrawFPS(30, 0);
        ball.Update(paddle.paddle);
        ball.Draw();
        paddle.Update();
        paddle.Draw();
        EndDrawing();
    }

    CloseWindow();
    CloseAudioDevice();
    return 0;
}