#include<bits/stdc++.h>
#include<raylib.h>
#include"fnHeader.h"
using namespace std;

int main(){
    const int width = 1280;
    const int height = 720;

    SetTargetFPS(60);
    InitWindow(width, height, "Bitwise-XO");

    grid = LoadImage("assets/grid.png");
    gridtexture = LoadTextureFromImage(grid);

    cursor = LoadImage("assets/selectcursor.png");
    cursortexture = LoadTextureFromImage(cursor);

    while(!WindowShouldClose()){
        if(!menuexit)menuscreen();

        if(gameover)endscreen();
        if(gameover)break; //end game
        
        if(mode)multiplayer();
    }

    UnloadTexture(gridtexture);
    UnloadImage(grid);
    UnloadTexture(cursortexture);
    UnloadImage(cursor);

    return 0;
}