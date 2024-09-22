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

    //loading assets
    Font pixelfont = LoadFont("assets/font/GomePixel-ARJd7.otf");

    menuasset = LoadImage("assets/menuasset1.png");
    menutexture = LoadTextureFromImage(menuasset);

    press_e_asset = LoadImage("assets/press_enter.png");
    press_e_texture  = LoadTextureFromImage(press_e_asset);

    gameplay_text1_asset = LoadImage("assets/gameplay_text1.png");
    gameplay_text1_texture = LoadTextureFromImage(gameplay_text1_asset);

    p1icon_asset = LoadImage("assets/p1icon.png");
    p1icon_texture = LoadTextureFromImage(p1icon_asset);
    p2icon_asset = LoadImage("assets/p2icon.png");
    p2icon_texture = LoadTextureFromImage(p2icon_asset);

    grid = LoadImage("assets/grid.png");
    gridtexture = LoadTextureFromImage(grid);

    xicon = LoadImage("assets/X_icon.png");
    xtexture = LoadTextureFromImage(xicon);
    oicon = LoadImage("assets/O_icon.png");
    otexture = LoadTextureFromImage(oicon);

    while(!WindowShouldClose()){
        if(!menuexit)menuscreen();

        if(gameover)break; 
        
        if(mode)multiplayer();
    }

    //handling open assets
    UnloadTexture(gridtexture);
    UnloadImage(grid);
    UnloadTexture(xtexture);
    UnloadImage(xicon);
    UnloadTexture(otexture);
    UnloadImage(oicon);
    UnloadTexture(menutexture);
    UnloadImage(menuasset);
    UnloadTexture(press_e_texture);
    UnloadImage(press_e_asset);
    UnloadTexture(gameplay_text1_texture);
    UnloadImage(gameplay_text1_asset);
    UnloadTexture(p1icon_texture);
    UnloadImage(p1icon_asset);
    UnloadTexture(p2icon_texture);
    UnloadImage(p2icon_asset);

    CloseAudioDevice();
    CloseWindow();

    return 0;
}