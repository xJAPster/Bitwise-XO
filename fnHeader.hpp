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
    inline void updateCursor(int& x, int& y);

    //rendering selection cursor
    void renderCursor(const int& x, const int& y);

    ~Cursor(){
        UnloadTexture(cursortexture);
        UnloadImage(cursor);
        UnloadSound(cursor_move);
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

    inline void drawGrid();

    ~Grid(){}
};