#include "fnHeader.h"
using namespace std;

int main(){
    const int width = 1280;
    const int height = 720;

    InitWindow(width, height, "bitwise XO");
    SetTargetFPS(60);
    InitAudioDevice();

    //loading assets
    pixelfont = LoadFont("assets/font/GomePixel-DYJX1.otf");

    menuasset = LoadImage("assets/menuasset2.png");
    menutexture = LoadTextureFromImage(menuasset);

    gameplay_text1_asset = LoadImage("assets/gameplay_text1.png");
    gameplay_text1_texture = LoadTextureFromImage(gameplay_text1_asset);

    p1icon_asset = LoadImage("assets/p1icon.png");
    p1icon_texture = LoadTextureFromImage(p1icon_asset);
    p2icon_asset = LoadImage("assets/p2icon.png");
    p2icon_texture = LoadTextureFromImage(p2icon_asset);

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
    UnloadFont(pixelfont);
    UnloadTexture(xtexture);
    UnloadImage(xicon);
    UnloadTexture(otexture);
    UnloadImage(oicon);

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