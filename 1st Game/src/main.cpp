#include <raylib.h>
#include "pong.h"

int main()
{
    Color black = Color{0, 0, 0, 255};

    Ball ball = Ball();
    Barre barre = Barre();

    InitWindow(screenWidth, screenHeight, "Pong with Raylib, by n3izvn");
    SetTargetFPS(60);
    ShowCursor();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(black);
        ball.Update(barre.x, barre.y);
        ball.Draw();
        barre.Move();
        barre.Draw();
        DrawFPS(0, 0);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}