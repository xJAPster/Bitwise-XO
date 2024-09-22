#pragma once
#include <bits/stdc++.h>
#include <raylib.h>
using namespace std;

extern bool menuexit, gameover, mode;
extern Image grid, xicon, oicon, menuasset, press_e_asset, gameplay_text1_asset, p1icon_asset, p2icon_asset;
extern Texture2D gridtexture, xtexture, otexture, menutexture, press_e_texture, gameplay_text1_texture, p1icon_texture, p2icon_texture;

void menuscreen();
void multiplayer();

class Cursor{
private:
    Image cursor;
    Texture cursortexture;

public:
    Cursor(){
        cursor = LoadImage("assets/selectcursor.png");
        cursortexture = LoadTextureFromImage(cursor);
    }

    //checking for user input
    inline void updateCursor(int& x, int& y) {
        if (IsKeyPressed(KEY_W) && y > 0) --y;
        if (IsKeyPressed(KEY_S) && y < 2) ++y;
        if (IsKeyPressed(KEY_A) && x > 0) --x;
        if (IsKeyPressed(KEY_D) && x < 2) ++x;
    }

    //rendering selection cursor
    void renderCursor(const int& x, const int& y) {
        int posX, posY;

        //x : 430, 583, 736
        //y : 160, 313, 466
        switch(x){
            case 0:
                posX = 430;
                break;
            case 1:
                posX = 583;
                break;
            case 2:
                posX = 736;
                break;
        }

        switch(y){
            case 0:
                posY = 160;
                break;
            case 1:
                posY = 313;
                break;
            case 2:
                posY = 466;
                break;
        }

        DrawTexture(cursortexture, posX, posY, WHITE);
    }

    ~Cursor(){
        UnloadTexture(cursortexture);
        UnloadImage(cursor);
    }
};
