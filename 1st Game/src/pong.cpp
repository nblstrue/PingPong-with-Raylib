#include "pong.h"
#include <raylib.h>
#include <iostream>

int a = 0, score = 0;
int fontsize = 20;
const char* p_res;

Ball::Ball()
{
    ball.x = screenWidth/2;
    ball.y = screenHeight/2;
    speedX = 5;
    speedY = 5;
    radius = 15;
    color = Color{255, 255, 0, 255};
}

void Ball::Update(Rectangle a)
{
    const char difficulty1[] = "Difficulty = Easy";
    const char difficulty2[] = "Difficulty = Medium";
    const char difficulty3[] = "Difficulty = Hard";
    const char difficulty4[] = "Difficulty = Impossible";

    ball.x += speedX;
    ball.y += speedY;
    p_res = TextFormat("Score = %d", score);

    if (ball.x + radius >= GetScreenWidth()){
        speedX *= -1;
    }
    if (ball.y + radius >= GetScreenHeight() || ball.y - radius <= 0){
        speedY *= -1;
    }
    if(CheckCollisionCircleRec(ball, radius, a))
    {
        speedX*=1.2;
        speedY*=1.2;
        speedX *= -1;
        score+=1;
    }
    if(ball.x - radius <= 0)
    {
        ball.x = screenWidth/2;
        ball.y = screenHeight/2;
        speedX = 5;
        speedY = 5;
        score = 0;
    }
    if(score < 10)
    {
        DrawText("By n3izvn", screenWidth-110, 0, fontsize, SKYBLUE);
        DrawText(difficulty1, 30, screenHeight-20, fontsize, GREEN);
        DrawText(p_res, 220, screenHeight-20, fontsize, BEIGE);
    }
    if(score < 20 && score >= 10)
    {
        DrawText("By n3izvn", screenWidth-110, 0, fontsize, SKYBLUE);
        DrawText(difficulty2, 30, screenHeight-20, fontsize, YELLOW);
        DrawText(p_res, 235, screenHeight-20, fontsize, BEIGE);
    }
    if(score < 30 && score >= 20)
    {
        DrawText("By n3izvn", screenWidth-110, 0, fontsize, SKYBLUE);
        DrawText(difficulty3, 30, screenHeight-20, fontsize, RED);
        DrawText(p_res, 220, screenHeight-20, fontsize, BEIGE);
    }
    if(score >= 35)
    {
        DrawText("By n3izvn", screenWidth-110, 0, fontsize, SKYBLUE);
        DrawText(difficulty4, 30, screenHeight-20, fontsize, MAGENTA);
        DrawText(p_res, 265, screenHeight-20, fontsize, BEIGE);
    }
    if(score >= 40)
    {
        DrawText("By n3izvn", screenWidth-110, 0, fontsize, SKYBLUE);
        DrawText("Congratulations, you somehow finished the game ! (Saving progress and obstacle in developpement...)", 390, screenHeight-20, fontsize, GOLD);
        DrawText(difficulty4, 30, screenHeight-20, fontsize, MAGENTA);
        DrawText(p_res, 265, screenHeight-20, fontsize, BEIGE);
    }
}

void Ball::Draw()
{
    DrawCircle(ball.x, ball.y, radius, color);
}

Paddle::Paddle()
{
    paddle.height = 100;
    paddle.width = 10;
    paddle.x = 10;
    paddle.y = 0;
    speedX = 7;
    speedY = 7;
    color = Color{255, 255, 0, 255};
}

void Paddle::Draw()
{
    DrawRectangle(paddle.x, paddle.y, paddle.width, paddle.height, color);
}

void Paddle::Update()
{
    if(IsKeyDown(KEY_DOWN))
    {
        paddle.y += speedY;
        if(paddle.y >= (screenHeight - 100))
        {
            paddle.y = (screenHeight - 100);
        }
    }
    else
    {
        if(IsKeyDown(KEY_UP))
        {
            paddle.y -= speedY;
            if(paddle.y < 0)
            {
                paddle.y = 0;
            }
        }
    }
}

