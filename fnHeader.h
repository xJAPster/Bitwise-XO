#pragma once
#include <bits/stdc++.h>
#include <raylib.h>
using namespace std;

extern bool menuexit, gameover, mode, draw;
extern Image grid, cursor, xicon, oicon, menuasset, press_e_asset, gameplay_text1_asset, p1icon_asset, p2icon_asset;
extern Texture2D gridtexture, cursortexture, xtexture, otexture, menutexture, press_e_texture, gameplay_text1_texture, p1icon_texture, p2icon_texture;

void menuscreen();
void multiplayer();
void endscreen();


