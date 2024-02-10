#include <src/pong.h>
#include <iostream>

int fontsize = 20, score = 0, done = 0;
int finish = 0, one = 0, two = 0, three = 0, four = 0;
const char* p_res;

Ball::Ball()
{
    ball.x = screenWidth/2;
    ball.y = screenHeight/2;
    speedX = 7;
    speedY = 7;
    radius = 10;
    color = Color{255, 255, 0, 255};
}

int Ball::stats()
{
    return score;
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
    DrawText("By n3izvn", screenWidth-100, 0, fontsize, SKYBLUE);

    if(score < 2 && done != 1)
    {
        DrawText("Stellar Ping Pong 1.4 - Try to hit a score of 100 to win the game !!", 20, 100, 40, LIGHTGRAY);
        DrawText("Use the UP and DOWN Arrow Keys to control the platform", 20, (screenHeight/2), 20, LIGHTGRAY);
        DrawText("Press ENTER to play the game and press ESC to exit the game", 20, (screenHeight/2)+50, 20, LIGHTGRAY);
        DrawText("Have fun i guess :) ", 20, (screenHeight/2)+100, 20, LIGHTGRAY);
    }
    if(score == 2)
        done = 1;
    if (ball.x + radius >= GetScreenWidth()){
        speedX *= -1;
    }
    if (ball.y + radius >= GetScreenHeight() || ball.y - radius <= 0){
        speedY *= -1;
    }
    if(CheckCollisionCircleRec(ball, radius, a))
    {
        speedX *= -1;
        score+=10;
    }
    if(ball.x - radius <= 0)
    {
        score = 0;
        ball.x = screenWidth/2;
        ball.y = screenHeight/1.22;
        speedX = 7;
        speedY = 7;
        one = 0;
        two = 0;
        three = 0;
        four = 0;
        finish = 0;
    }
    if(score < 10)
    {
        if(one == 0)
        {
            speedX = 9;
            speedY = 9;
            one = 1;
            two = 0;
            three = 0;
            four = 0;
            score = 0;
        }
        DrawText(difficulty1, (screenWidth/2)-100, 0, fontsize, GREEN);
        DrawText(p_res, (screenWidth/2)+80, 0, fontsize, BEIGE);
    }
    if(score < 30 && score >= 10)
    {
        if(two == 0)
        {
            speedX = 12;
            speedY = 12;
            one = 0;
            two = 1;
            three = 0;
            four = 0;
        }
        DrawText(difficulty2, (screenWidth/2)-100, 0, fontsize, YELLOW);
        DrawText(p_res, (screenWidth/2)+210, 0, fontsize, BEIGE);
    }
    if(score < 70 && score >= 30)
    {
        if(three == 0)
        {
            speedX = 15;
            speedY = 15;
            one = 0;
            two = 0;
            three = 1;
            four = 0;
        }
        DrawText(difficulty3, (screenWidth/2)-100, 0, fontsize, RED);
        DrawText(p_res, (screenWidth/2)+80, 0, fontsize, BEIGE);
    }
    if(score < 100 && score >= 70)
    {
        if(four == 0)
        {
            speedX = 20;
            speedY = 20;
            one = 0;
            two = 0;
            three = 0;
            four = 1;
        }
        DrawText(difficulty4, (screenWidth/2)-100, 0, fontsize, MAGENTA);
        DrawText(p_res, (screenWidth/2)+290, 0, fontsize, BEIGE);
    }
    if(score >= 100)
    {
        if(finish == 0)
        {
            one = 0;
            two = 0;
            three = 0;
            four = 0;
            speedX = 7;
            speedY = 7;
            finish = 1;
        }
        DrawText(difficulty4, (screenWidth/2)-100, 0, fontsize, MAGENTA);
        DrawText(p_res, (screenWidth/2)+290, 0, fontsize, BEIGE);
        DrawText("Congratulations, you somehow finished the game ! (Progress and Obstacles in developpement...)", 390, 0, fontsize, GOLD);
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
    paddle.x = 0;
    paddle.y = 0;
    speedX = 8;
    speedY = 8;
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
