#pragma once
#include <bits/stdc++.h>
#include <raylib.h>
using namespace std;

extern bool menuexit, gameover, mode;
extern Font pixelfont;
extern Sound token_placed, victoryjingle, invalid_move;
extern Image xicon, oicon, menuasset;
extern Texture2D xtexture, otexture, menutexture;

void menuscreen();
void multiplayer();

//class declaration space
class Cursor{
private:
    Image cursor;
    Texture cursortexture;
    Sound cursor_move;

public:
    Cursor(){
        cursor = LoadImage("assets/vfx/selectcursor.png");
        cursortexture = LoadTextureFromImage(cursor);
        cursor_move = LoadSound("assets/sfx/cursor_move.mp3");
    }

    //checking for user input
    inline void updateCursor(int& x, int& y){
        if (IsKeyPressed(KEY_W) && y > 0){
            --y;
            PlaySound(cursor_move);
        }
        if (IsKeyPressed(KEY_S) && y < 2){
            ++y;
            PlaySound(cursor_move);
        }
        if (IsKeyPressed(KEY_A) && x > 0){
            --x;
            PlaySound(cursor_move);
        }
        if (IsKeyPressed(KEY_D) && x < 2){
            ++x;
            PlaySound(cursor_move);
        }
    }

    //rendering selection cursor
    void renderCursor(const int& x, const int& y) {
        int posX, posY;

        switch(x){
            case 0:
                posX = 433;
                break;
            case 1:
                posX = 582;
                break;
            case 2:
                posX = 732;
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

class Grid{
private:
    int width, height;

public:
    Grid(){
        width=30;
        height=425;
    }

    inline void drawGrid(){
        DrawRectangle(555,165, width,height, WHITE);
        DrawRectangle(705,165, width,height, WHITE);

        DrawRectangle(433,287, height,width, WHITE);
        DrawRectangle(433,438, height,width, WHITE);
    }

    ~Grid(){}
};