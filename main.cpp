#include<bits/stdc++.h>
#include<raylib.h>
#include "fnHeader.h"
using namespace std;

int main(){
    const int width = 1280;
    const int height = 720;

    InitWindow(width, height, "Bitwise-XO");
    SetTargetFPS(60);
    InitAudioDevice();

    grid = LoadImage("assets/grid.png");
    gridtexture = LoadTextureFromImage(grid);
    cursor = LoadImage("assets/selectcursor.png");
    cursortexture = LoadTextureFromImage(cursor);

    xicon = LoadImage("assets/X_icon.png");
    xtexture = LoadTextureFromImage(xicon);
    oicon = LoadImage("assets/O_icon.png");
    otexture = LoadTextureFromImage(oicon);

    while(!WindowShouldClose()){
        if(!menuexit)menuscreen();

        if(gameover)endscreen();
        if(gameover)break; 
        
        if(mode)multiplayer();
    }

    UnloadTexture(gridtexture);
    UnloadImage(grid);
    UnloadTexture(cursortexture);
    UnloadImage(cursor);
    UnloadTexture(xtexture);
    UnloadImage(xicon);
    UnloadTexture(otexture);
    UnloadImage(oicon);


    CloseAudioDevice();
    CloseWindow();

    return 0;
}