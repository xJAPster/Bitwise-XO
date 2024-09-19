#include <bits/stdc++.h>
#include <raylib.h>

#ifndef fnForwardDec
#define fnForwardDec

using namespace std;
extern bool menuexit, gameover, mode;
extern Image grid, cursor;
extern Texture2D gridtexture, cursortexture;

void menuscreen();
void inputChecker(int& x, int& y);
void rendercursor();
void multiplayer();
void endscreen();

#endif
