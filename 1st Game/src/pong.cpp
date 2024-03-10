#include <src/pong.h>
#include <iostream>

const char *p_res;
int score = 0;

Ball::Ball()
{
    ball.x = screenWidth/2; ball.y = screenHeight/2;
    speedX = 9; speedY = 9;
    radius = 10;
    color = Color{255, 255, 0, 255};
}

int Ball::stats()
{
    return score;
}

void Ball::reLoading()
{
    if(IsKeyPressed(KEY_R))
    {
        ball.x = screenWidth-50;
        ball.y = screenHeight-50;
    }
}

void Ball::Update(Rectangle a)
{
    const char difficulty1[] = "Difficulty = Easy", difficulty2[] = "Difficulty = Medium", difficulty3[] = "Difficulty = Hard", difficulty4[] = "Difficulty = Impossible";
    static int finish = 0, one = 0, two = 0, three = 0, four = 0, fontsize = 20;

    ball.x += speedX; ball.y += speedY;
    p_res = TextFormat("Score = %d", score);

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
        speedX *= -1;
        //score -= 2;
        if(score < 0)
            score = 0;
        if(score == 0)
            one = 0;
    }
    if(score < 10)
    {
        if(one == 0)
        {
            speedX = 12; speedY = 12;
            one = 1; two = 0; three = 0; four = 0;
        }
        DrawText(difficulty1, (screenWidth/2)-100, 0, fontsize, GREEN);
        DrawText(p_res, (screenWidth/2)-80, 25, fontsize, BEIGE);
    }
    if(score < 30 && score >= 10)
    {
        if(two == 0)
        {
            speedX = 15; speedY = 15;
            one = 0; two = 1; three = 0; four = 0;
        }
        DrawText(difficulty2, (screenWidth/2)-110, 0, fontsize, YELLOW);
        DrawText(p_res, (screenWidth/2)-80, 25, fontsize, BEIGE);
    }
    if(score < 70 && score >= 30)
    {
        if(three == 0)
        {
            speedX = 18; speedY = 18;
            one = 0; two = 0; three = 1; four = 0;
        }
        DrawText(difficulty3, (screenWidth/2)-100, 0, fontsize, RED);
        DrawText(p_res, (screenWidth/2)-80, 25, fontsize, BEIGE);
    }
    if(score < 100 && score >= 70)
    {
        if(four == 0)
        {
            speedX = 21; speedY = 21;
            one = 0; two = 0; three = 0; four = 1;
        }
        DrawText(difficulty4, (screenWidth/2)-140, 0, fontsize, MAGENTA);
        DrawText(p_res, (screenWidth/2)-80, 25, fontsize, BEIGE);
    }
    if(score >= 100)
    {
        if(finish == 0)
        {
            one = 0; two = 0; three = 0; four = 0; finish = 1;
            speedX = 7; speedY = 7;
        }
        DrawText(difficulty4, (screenWidth/2)-140, 0, fontsize, MAGENTA);
        DrawText(p_res, (screenWidth/2)-80, 25, fontsize, BEIGE);
        DrawText("Congratulations, you somehow finished the game !", screenWidth-510, screenHeight-20, fontsize, GOLD);
    }
}

void Ball::Draw()
{
    reLoading();
    DrawCircle(ball.x, ball.y, radius, color);
}

Paddle::Paddle()
{
    paddle.height = 100; paddle.width = 10;
    paddle.x = 0; paddle.y = 0;
    speedX = 10; speedY = 10;
    color = Color{255, 255, 0, 255};
}

void Paddle::Draw()
{
    DrawRectangle(paddle.x, paddle.y, paddle.width, paddle.height, color);
}

void Paddle::Update()
{
    if(score == 70)
    {
        speedX = 28; speedY = 28;
    }
    if(score == 30)
    {
        speedX = 14; speedY = 14;
    }
    if(score == 0 || score >= 100)
    {
        speedX = 10; speedY = 10;
    }

    if(IsKeyDown(KEY_DOWN))
    {
        paddle.y += speedY;
        if(paddle.y >= (screenHeight - 100))
            paddle.y = (screenHeight - 100);
    }
    else
    {
        if(IsKeyDown(KEY_UP))
        {
            paddle.y -= speedY;
            if(paddle.y < 0)
                paddle.y = 0;
        }
    }
}
