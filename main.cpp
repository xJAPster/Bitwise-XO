#include "fnHeader.hpp"
using namespace std;

int main(){
    const int width = 1280;
    const int height = 720;

    InitWindow(width, height, "bitwise XO");
    SetTargetFPS(60);
    InitAudioDevice();

    SetSoundVolume(token_placed, 25);
    SetSoundVolume(victoryjingle, 25);

    //loading assets
    pixelfont = LoadFont("assets/font/GomePixel-DYJX1.otf");

    invalid_move = LoadSound("assets/sfx/invalid_move.mp3");
    victoryjingle = LoadSound("assets/sfx/victoryjingle.mp3");
    token_placed = LoadSound("assets/sfx/token_placed.mp3");

    while(!WindowShouldClose()){
        if(!menuexit)menuscreen();

        if(gameover)break; 
        
        if(mode)multiplayer();
    }

    //handling open assets
    UnloadFont(pixelfont);
    UnloadSound(victoryjingle);
    UnloadSound(invalid_move);
    UnloadSound(token_placed);

    CloseAudioDevice();
    CloseWindow();

    return 0;
}