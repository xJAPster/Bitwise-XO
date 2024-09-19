#include "fnHeader.h"

bool menuexit = 0, gameover = 0, mode = 1;
Image grid, cursor;
Texture2D gridtexture, cursortexture;

void menuscreen() {
    while (!WindowShouldClose() && !menuexit) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("MENU SCREEN", 640, 360, 30, WHITE); // placeholder
        EndDrawing();

        if (IsKeyPressed(KEY_ENTER)) {
            menuexit = 1;
            ClearBackground(BLACK);
        }
    }
}

inline void inputChecker(int& x, int& y) {
    if (IsKeyPressed(KEY_W) && x > 0) --x;
    if (IsKeyPressed(KEY_S) && x < 2) ++x;
    if (IsKeyPressed(KEY_A) && y > 0) --y;
    if (IsKeyPressed(KEY_D) && y < 2) ++y;
}

void rendercursor() {
    DrawTexture(cursortexture, 430, 170, WHITE);
}

void multiplayer() {
    int x = 0, y = 0, turncount = 0;
    bool win = 0, turn = 1;
    vector<vector<char>> mat(3, vector<char>(3, ' '));

    while (!WindowShouldClose() && !win) {
        inputChecker(x, y);
        // function to render selection cursor
        // function to render placed tokens

        if (IsKeyPressed(KEY_ENTER) && mat[x][y] == ' ') {
            mat[x][y] = (turn) ? 'X' : '0'; // placing token
            turn = !turn;
            ++turncount;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(gridtexture, 0, 0, WHITE);
        rendercursor();
        EndDrawing();

        if (x == 2 && y == 2) {
            win = 1;
            gameover = 1;
        }
    }
}

void endscreen() {
    while (!WindowShouldClose() && gameover) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("JOEVER SCREEN", 640, 360, 30, WHITE); // placeholder
        EndDrawing();

        if (IsKeyPressed(KEY_ENTER)) return;
    }
}
