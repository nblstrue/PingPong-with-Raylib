#include <raylib.h>
#include <src/pong.h>
#include <vector>
#include <list>

int place = 0, ground = 0;
int *p_place = &place, *p_grd = &ground;
float scol_atm = 0.0f, scol_earth1 = 0.0f, scol_earth2 = 0.0f, scol_space = 0.0f;
const char* name_music[] = {"Ouranos Island", "Tails Mvt", "Arrow of Time Remix", "Ultra Necrozma Remix", "Egg Reverie Remix"};
const char* path_music[] = {"src/aud/Ouranos Island.mp3",
                            "src/aud/Tails Mvt.mp3",
                            "src/aud/Arrow_of_Time_Remix.mp3",
                            "src/aud/ULTRA_NECROZMA.mp3",
                            "src/aud/Egg Reverie Zone Remix.mp3"
                           };
Ball ball = Ball();
Paddle paddle = Paddle();
std::vector<Texture2D> Img;
std::vector<Music> Playlist;
Color black = Color{0, 0, 0, 255};

void Img_init(void);
void Back(int a);
void UnloadingTextures(void);
void music_init(void);
void music_update(int a, int *track, int b);
void framing(int f);
void Begin(void);

int main()
{
    InitWindow(screenWidth, screenHeight, "Stellar Ping Pong");
    ToggleFullscreen();
    SetTargetFPS(60);
    ShowCursor();
    InitAudioDevice();
    music_init();
    Img_init();
    PlayMusicStream(Playlist[0]);
    Begin();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(black);
        //Back(ball.stats());
        int frames = GetFPS();
        framing(frames);
        ball.Update(paddle.paddle);
        music_update(ball.stats(), p_place, place);
        ball.Draw();
        paddle.Update();
        paddle.Draw();
        EndDrawing();
    }
    
    CloseWindow();
    CloseAudioDevice();
    return 0;
}

void music_init(void)
{
    Playlist.push_back(LoadMusicStream(path_music[0]));
    Playlist.push_back(LoadMusicStream(path_music[1]));
    Playlist.push_back(LoadMusicStream(path_music[2]));
    Playlist.push_back(LoadMusicStream(path_music[3]));
    Playlist.push_back(LoadMusicStream(path_music[4]));
}

void music_update(int a, int *track, int b)
{
    if(a == 0 && *track != 0)
    {
        StopMusicStream(Playlist[*track]);
        PlayMusicStream(Playlist[0]);
        *track = 0;
    }
    else
    {
        if(a == 10 && *track != 1)
        {
            StopMusicStream(Playlist[*track]);
            PlayMusicStream(Playlist[1]);
            *track = 1;
        }
        else
        {
            if(a == 30 && *track != 2)
            {
                StopMusicStream(Playlist[*track]);
                PlayMusicStream(Playlist[2]);
                *track = 2;
            }
            else
            {
                if(a == 70 && *track != 3)
                {
                    StopMusicStream(Playlist[*track]);
                    PlayMusicStream(Playlist[3]);
                    *track = 3;
                }
                else
                {
                    if(a == 100 && *track != 4)
                    {
                        StopMusicStream(Playlist[*track]);
                        PlayMusicStream(Playlist[4]);
                        *track = 4;
                    }
                    else
                    {
                        UpdateMusicStream(Playlist[b]);
                        DrawText(TextFormat("Song = %s", name_music[b]), screenWidth-300, 0, 20, LIME);
                    }
                }
            }
        }
    }
}

void framing(int f)
{
    if(f < 20)
        DrawText(TextFormat("%d FPS", f), 20, 0, 20, RED);

    if(f < 45 && f >= 20)
        DrawText(TextFormat("%d FPS", f), 20, 0, 20, YELLOW);

    if(f >= 45)
        DrawText(TextFormat("%d FPS", f), 20, 0, 20, GREEN);
}

void Begin()
{
    while(!IsKeyPressed(KEY_ENTER))
    {
        UpdateMusicStream(Playlist[0]);
        BeginDrawing();
        ClearBackground(black);
        DrawText("Stellar Ping Pong 1.4 - By n3izvn", 200, 100, 40, RED);
        DrawText("Try to hit a score of 100 to win the game !!", 200, 160, 40, YELLOW);
        DrawText("Use the UP and DOWN Arrow Keys to control the platform", 200, (screenHeight/2), 20, GREEN);
        DrawText("Press ENTER to play the game and press ESC to exit the game", 200, (screenHeight/2)+50, 20, PURPLE);
        DrawText("Have fun i guess :) ", 200, (screenHeight/2)+100, 20, BLUE);
        paddle.Update();
        paddle.Draw();

        if(IsKeyPressed(KEY_ESCAPE))
        {
            EndDrawing();
            CloseWindow();
            CloseAudioDevice();
            exit(0);
        }

        EndDrawing();
    }
}

void Img_init()
{
    Img.push_back(LoadTexture("src/img/1e64c3289a248160c26a3b57b221e282.png"));
    Img.push_back(LoadTexture("src/img/3CDxl1.png"));
    Img.push_back(LoadTexture("src/img/2-2-space-free-png-image.png"));
}

void Back(int a)
{
    if(a < 30)
    {
        Rectangle Source;
        Rectangle Destination;
        Vector2 vct;

        Source.height = 562;
        Source.width = 1000;
        Source.x = 0;
        Source.y = 0;

        Destination.height = 1080;
        Destination.width = 1920;
        Destination.x = 0;
        Destination.y = 0;

        DrawTexturePro(Img[0], Source, Destination, vct, 0.0f, LIGHTGRAY);
    }

    if(a < 70 && a >= 30)
    {
        Rectangle Source;
        Rectangle Destination;
        Vector2 vct;

        Source.height = 448;
        Source.width = 1280;
        Source.x = 0;
        Source.y = 0;

        Destination.height = 1080;
        Destination.width = 1920;
        Destination.x = 0;
        Destination.y = 0;

        DrawTexturePro(Img[1], Source, Destination, vct, 0.0f, LIGHTGRAY);
    }

    if(a >= 70)
    {
        Rectangle Source;
        Rectangle Destination;
        Vector2 vct;

        Source.height = 1000;
        Source.width = 1500;
        Source.x = 0;
        Source.y = 0;

        Destination.height = 1080;
        Destination.width = 1920;
        Destination.x = 0;
        Destination.y = 0;

        DrawTexturePro(Img[2], Source, Destination, vct, 0.0f, LIGHTGRAY);
    }
}

void UnloadingTextures()
{
    UnloadTexture(Img[0]);
    UnloadTexture(Img[1]);
    UnloadTexture(Img[2]);
}

