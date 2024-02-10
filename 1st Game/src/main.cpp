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
std::vector<Music> Playlist;
Color black = Color{0, 0, 0, 255};

void music_init(void);
void music_update(int a, int *track, int b);
void framing(int f);

int main()
{
    InitWindow(screenWidth, screenHeight, "Stellar Ping Pong");
    ToggleFullscreen();
    SetTargetFPS(60);
    ShowCursor();
    InitAudioDevice();
    music_init();
    PlayMusicStream(Playlist[0]);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(black);
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
                        DrawText(TextFormat("Song = %s", name_music[b]), screenWidth-410, 0, 20, LIME);
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
