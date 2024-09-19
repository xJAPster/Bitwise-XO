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
    if (IsKeyPressed(KEY_W) && y > 0) --y;
    if (IsKeyPressed(KEY_S) && y < 2) ++y;
    if (IsKeyPressed(KEY_A) && x > 0) --x;
    if (IsKeyPressed(KEY_D) && x < 2) ++x;
}

void rendercursor(const int& x, const int& y) {
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

void multiplayer() {
    int x = 0, y = 0, turncount = 0;
    bool win = 0, turn = 1;
    vector<vector<char>> mat(3, vector<char>(3, ' '));

    while (!WindowShouldClose() && !win) {
        inputChecker(x, y);
        // function to render selection cursor
        // function to render placed tokens

        if (IsKeyPressed(KEY_ENTER) && mat[x][y] == ' ') {
            mat[y][x] = (turn) ? 'X' : '0'; // placing token
            turn = !turn;
            ++turncount;
        }

        BeginDrawing();

        ClearBackground(BLACK);
        DrawTexture(gridtexture, 0, 0, WHITE);
        rendercursor(x,y);

        EndDrawing();

        if (x == 2 && y == 2) { //temporary gameover condition, replace with win validation
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
