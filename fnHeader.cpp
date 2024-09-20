#include "fnHeader.h"

bool menuexit = 0, gameover = 0, mode = 1, draw = 0;
Image grid, cursor,  xicon, oicon, menuasset, press_e_asset, gameplay_text1_asset, p1icon_asset, p2icon_asset;
Texture2D gridtexture, cursortexture, xtexture, otexture, menutexture, press_e_texture, gameplay_text1_texture, p1icon_texture, p2icon_texture;

void menuscreen() {
    float interval = 1.0;
    float timeElapsed;
    
    while (!WindowShouldClose() && !menuexit) {
        timeElapsed = GetTime();
        
        BeginDrawing();

        ClearBackground(BLACK);
        DrawTexture(menutexture, 0, 0, WHITE);
       
        bool shouldDraw = fmod(timeElapsed, interval*2) < interval;
        if(shouldDraw)DrawTexture(press_e_texture, 430, 450, WHITE);  //blinking 'press enter to start' text

        EndDrawing();

        if (IsKeyPressed(KEY_ENTER)) {
            menuexit = 1;
            ClearBackground(BLACK);
        }
    }
}

//checking for user input
inline void inputChecker(int& x, int& y) {
    if (IsKeyPressed(KEY_W) && y > 0) --y;
    if (IsKeyPressed(KEY_S) && y < 2) ++y;
    if (IsKeyPressed(KEY_A) && x > 0) --x;
    if (IsKeyPressed(KEY_D) && x < 2) ++x;
}

//rendering selection cursor
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

//rendering placed tokens
void renderstate(const vector<vector<char>>& mat){
    int posX, posY;

    for(int y=0 ; y<3 ; ++y){
        for(int x=0 ; x<3 ; ++x){
            if(mat[y][x]=='X'){
                switch(x){
                case 0:
                    posX = 445;
                    break;
                case 1:
                    posX = 598;
                    break;
                case 2:
                    posX = 751;
                    break;
                }

                switch(y){
                    case 0:
                        posY = 175;
                        break;
                    case 1:
                        posY = 328;
                        break;
                    case 2:
                        posY = 481;
                        break;
                }
                DrawTexture(xtexture, posX, posY, WHITE);
            }

            else if(mat[y][x]=='O'){
                switch(x){
                case 0:
                    posX = 445;
                    break;
                case 1:
                    posX = 598;
                    break;
                case 2:
                    posX = 751;
                    break;
                }

                switch(y){
                    case 0:
                        posY = 175;
                        break;
                    case 1:
                        posY = 328;
                        break;
                    case 2:
                        posY = 481;
                        break;
                }
                DrawTexture(otexture, posX, posY, WHITE);
            }
        }
    }
}

bool winvalidation(const vector<vector<char>>& mat){
    // row and column check
    for (int i = 0; i < 3; ++i) {
        if (mat[i][0] != ' ' && mat[i][0] == mat[i][1] && mat[i][1] == mat[i][2]) return true;
        if (mat[0][i] != ' ' && mat[0][i] == mat[1][i] && mat[1][i] == mat[2][i]) return true;
    }

    // diagonal check
    if (mat[0][0] != ' ' && mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2]) return true;
    if (mat[2][0] != ' ' && mat[2][0] == mat[1][1] && mat[1][1] == mat[0][2]) return true;

    return false;
}

void multiplayer() {
    int x = 0, y = 0, turncount = 0;
    bool win = 0, turn = 1;
    vector<vector<char>> mat(3, vector<char>(3, ' '));

    while (!WindowShouldClose() && (!win && !draw)) {
        inputChecker(x, y);

        if(IsKeyPressed(KEY_SPACE) && mat[y][x] == ' '){
            mat[y][x] = (turn)? 'X' : 'O'; // placing token
            turn = !turn;
            ++turncount;
        }
        
        BeginDrawing();

        ClearBackground(BLACK);
        DrawTexture(gridtexture, 0, 0, WHITE); //drawing the grid

        DrawTexture(gameplay_text1_texture, 250, 40, WHITE);
        if(turn)DrawTexture(p1icon_texture, 470, 35, WHITE);
        else DrawTexture(p2icon_texture, 470, 35, WHITE);

        rendercursor(x,y); //rendering the cursor
        renderstate(mat); //rendering the game state/placed tokens

        EndDrawing();

        if (winvalidation(mat) || turncount==9) { 
            if(turncount==9)draw=1;
            else win=1;

            gameover=1;
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
