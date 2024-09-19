#pragma once
#include <bits/stdc++.h>
#include <raylib.h>

using namespace std;
extern bool menuexit, gameover, mode;
extern Image grid, cursor, xicon, oicon;
extern Texture2D gridtexture, cursortexture, xtexture, otexture;

void menuscreen();
void multiplayer();
void endscreen();


