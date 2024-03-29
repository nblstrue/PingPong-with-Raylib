#include <raylib.h>
#include <src/pong.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <src/date.h>

/*By JeffM, on the offical discord server */
Ball ball = Ball();
std::string player_name;
Paddle paddle = Paddle();
std::vector<Music> Playlist;
Color backColor = Color{0, 0, 0, 0};

void Begin(void);
void Reload(void);
void framing(void);
void music_init(void);
void name_recup(void);
void Shotscreen(void);
void saving(int a, int *b);
void music_update(int a, int *track, int b);

int main()
{
    static int place = 0, save = 0, *p_place = &place;

    name_recup();
    InitWindow(screenWidth, screenHeight, "Stellar Ping Pong");
    HideCursor();
    InitAudioDevice();
    music_init();
    PlayMusicStream(Playlist[0]);
    Begin();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(backColor);
        framing();
        ball.Update(paddle.paddle);
        saving(ball.stats(), &save);
        music_update(ball.stats(), p_place, place);
        ball.Draw();
        paddle.Update();
        paddle.Draw();
        EndDrawing();
        Shotscreen();
    }
    
    CloseWindow();
    CloseAudioDevice();
    return 0;
}

void Shotscreen()
{
    static int shots = 0;
    
    if(IsKeyDown(KEY_S) && (IsKeyDown(KEY_RIGHT_CONTROL) || IsKeyDown(KEY_LEFT_CONTROL)))
    {
        TakeScreenshot(TextFormat("Screenshot_%d.png", shots));
        shots++;
    }
}

void music_init(void)
{
    const char* path_music[] =
    {
        "src/aud/Ouranos Island.mp3",
        "src/aud/Tails Mvt.mp3",
        "src/aud/Arrow_of_Time_Remix.mp3",
        "src/aud/ULTRA_NECROZMA.mp3",
        "src/aud/Egg Reverie Zone Remix.mp3"
    };
        
    Playlist.push_back(LoadMusicStream(path_music[0]));
    Playlist.push_back(LoadMusicStream(path_music[1]));
    Playlist.push_back(LoadMusicStream(path_music[2]));
    Playlist.push_back(LoadMusicStream(path_music[3]));
    Playlist.push_back(LoadMusicStream(path_music[4]));
}

void music_update(int a, int *track, int b)
{
    const char* name_music[] = {"Ouranos Island", "Tails Mvt", "Arrow of Time Remix", "Ultra Necrozma Remix", "Egg Reverie Remix"};

    if(a < 10 && *track != 0)
    {
        StopMusicStream(Playlist[*track]);
        PlayMusicStream(Playlist[0]);
        *track = 0;
    }
    else
    {
        if(a >= 10 && a < 30 && *track != 1)
        {
            StopMusicStream(Playlist[*track]);
            PlayMusicStream(Playlist[1]);
            *track = 1;
        }
        else
        {
            if(a >= 30 && a < 70 && *track != 2)
            {
                StopMusicStream(Playlist[*track]);
                PlayMusicStream(Playlist[2]);
                *track = 2;
            }
            else
            {
                if(a >= 70 && a < 100 && *track != 3)
                {
                    StopMusicStream(Playlist[*track]);
                    PlayMusicStream(Playlist[3]);
                    *track = 3;
                }
                else
                {
                    if(a >= 100 && *track != 4)
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

void framing()
{
    int f = GetFPS();

    if(f < 20)
        DrawText(TextFormat("%d FPS", f), 20, 0, 20, RED);

    if(f < 45 && f >= 20)
        DrawText(TextFormat("%d FPS", f), 20, 0, 20, YELLOW);

    if(f >= 45)
        DrawText(TextFormat("%d FPS", f), 20, 0, 20, GREEN);
}

void name_recup()
{
    std::cout << "Veuillez ecrire votre nom de joueur (50 caracteres maximum)\n=>";
    std::getline(std::cin, player_name);
}

void Begin()
{
    while(!IsKeyPressed(KEY_ENTER))
    {
        UpdateMusicStream(Playlist[0]);
        BeginDrawing();
        ClearBackground(backColor);
        DrawText("Stellar Pong Game v1.8.5 - by n3izvn", 200, 120, 40, RED);
        DrawText("Try to hit a score of 100 to win the game !!", 200, 200, 30, WHITE);
        DrawText("Press ENTER to get the controls of the game", 200, (screenHeight/2)+50, 20, YELLOW);

        if(IsKeyPressed(KEY_ESCAPE))
        {
            EndDrawing();
            CloseWindow();
            CloseAudioDevice();
            exit(0);
        }

        EndDrawing();
    }

    while(!IsKeyPressed(KEY_G))
    {
        UpdateMusicStream(Playlist[0]);
        BeginDrawing();
        ClearBackground(backColor);
        DrawText("Stellar Pong Game v1.8.5 - by n3izvn", 200, 120, 40, RED);
        DrawText("Press the G Key to play the game or press ESC to exit the game", 200, (screenHeight/2), 20, ORANGE);
        DrawText("You can take a screenshot in-game with CTRL Key + S Key", 200, (screenHeight/2)+50, 20, YELLOW);
        DrawText("The game will get unfairly harder and harder with banger music", 200, (screenHeight/2)+100, 20, GREEN);
        DrawText("If there is a issue, press the R Key to reload the game", 200, (screenHeight/2)+150, 20, PURPLE);
        DrawText("Have fun i guess :)", 200, (screenHeight/2)+200, 20, BLUE);
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
        Shotscreen();
    }
}

void saving(int a, int *b)
{
    /*By Howard Hinnant, on stack overflow*/
    if(a >= 100 && *b != 1)
    {
        using namespace date;
        using namespace std::chrono;
        std::ofstream demo1("spg.save");
        demo1 << player_name << " won the game\nTime = " << system_clock::now() << "\n\n";
        demo1.close();
        *b = 1;
    }
}
