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

    CloseAudioDevice();
    CloseWindow();

    return 0;
}