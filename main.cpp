#include<bits/stdc++.h>
#include<raylib.h>
#include "fnHeader.h"
using namespace std;

int main(){
    const int width = 1280;
    const int height = 720;

    InitWindow(width, height, "bitwise XO");
    SetTargetFPS(60);
    InitAudioDevice();

    grid = LoadImage("assets/grid.png");
    gridtexture = LoadTextureFromImage(grid);
    cursor = LoadImage("assets/selectcursor.png");
    cursortexture = LoadTextureFromImage(cursor);

    menuasset = LoadImage("assets/menuasset1.png");
    menutexture = LoadTextureFromImage(menuasset);

    press_e_asset = LoadImage("assets/press_enter.png");
    press_e_texture  = LoadTextureFromImage(press_e_asset);

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