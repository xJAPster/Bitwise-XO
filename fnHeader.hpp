#pragma once
#include <bits/stdc++.h>
#include <raylib.h>
using namespace std;

extern bool menuexit, gameover, mode;
extern Font pixelfont;
extern Sound token_placed, victoryjingle, invalid_move;
extern Texture menutexture;

void menuscreen();
void multiplayer();

//class declaration space

class Cursor{
private:
    Texture cursortexture;
    Sound cursor_move;

public:
    Cursor(){
        cursortexture = LoadTexture("assets/vfx/selectcursor.png");
        cursor_move = LoadSound("assets/sfx/cursor_move.mp3");
    }

    //checking for user input
    inline void updateCursor(int& x, int& y);

    //rendering selection cursor
    void renderCursor(const int& x, const int& y);

    ~Cursor(){
        UnloadTexture(cursortexture);
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

class Token{
private:
    Texture xtexture, otexture;

public:
    Token(){
        xtexture = LoadTexture("assets/vfx/X_icon.png");
        otexture = LoadTexture("assets/vfx/O_icon.png");
    }

    void renderTokens(const vector<vector<char>>& mat);

    ~Token(){
        UnloadTexture(xtexture);
        UnloadTexture(otexture);
    }
};

class Confetti{
private: 
    Texture redconfetti, blueconfetti;

public:
    Confetti(){
        redconfetti= LoadTexture("assets/vfx/redconfetti.png");
        blueconfetti = LoadTexture("assets/vfx/blueconfetti.png");
    }

    void renderCelebration(const float& timeStarted, const bool& turn);

    ~Confetti(){
        UnloadTexture(redconfetti);
        UnloadTexture(blueconfetti);
    }
};