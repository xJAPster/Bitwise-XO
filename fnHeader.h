#pragma once
#include <bits/stdc++.h>
#include <raylib.h>

using namespace std;
extern bool menuexit, gameover, mode;
extern Image grid, cursor, xicon, oicon, menuasset, press_e_asset;
extern Texture2D gridtexture, cursortexture, xtexture, otexture, menutexture, press_e_texture;

void menuscreen();
void multiplayer();
void endscreen();


