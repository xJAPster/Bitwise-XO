#include "fnHeader.hpp"

bool menuexit = 0, gameover = 0, mode = 1;
Font pixelfont;
Sound token_placed, victoryjingle, invalid_move;
Texture menutexture;

void menuscreen() {
    float interval = 1.0;
    float timeElapsed;
    bool shouldDraw;

    //loading relevant menu screen vfx assets
    menutexture = LoadTexture("assets/vfx/menuasset2.png");
    
    while (!WindowShouldClose() && !menuexit) {
        BeginDrawing();

        ClearBackground(BLACK);
        DrawTexture(menutexture, 305, 145, WHITE);

        timeElapsed = GetTime();
        shouldDraw = fmod(timeElapsed, interval * 2) < interval;
        if(shouldDraw)DrawTextEx(pixelfont, "press ENTER to start", {430, 470}, 50, 0, WHITE);

        EndDrawing();

        if (IsKeyPressed(KEY_ENTER)) {
            menuexit = 1;
            ClearBackground(BLACK);
        }
    }
    UnloadTexture(menutexture);
}

//class Token member declaration state
void Token::renderTokens(const vector<vector<char>>& mat){
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

//class Cursor member function definitions
inline void Cursor::updateCursor(int& x, int& y){
    if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && y > 0){
        --y;
        PlaySound(cursor_move);
    }
    if ((IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) && y < 2){
        ++y;
        PlaySound(cursor_move);
    }
    if ((IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) && x > 0){
        --x;
        PlaySound(cursor_move);
    }
    if ((IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) && x < 2){
        ++x;
        PlaySound(cursor_move);
    }
}

void Cursor::renderCursor(const int& x, const int& y) {
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

//class Grid member function definitions
inline void Grid::drawGrid(){
    DrawRectangle(555,165, width,height, WHITE);
    DrawRectangle(705,165, width,height, WHITE);

    DrawRectangle(433,287, height,width, WHITE);
    DrawRectangle(433,438, height,width, WHITE);
}

bool winvalidation(const vector<vector<char>>& mat, vector<bool>& winflag){
    // row and column check
    for (int i = 0; i < 3; ++i) {
        if (mat[i][0] != ' ' && mat[i][0] == mat[i][1] && mat[i][1] == mat[i][2]){
            winflag[i]=1;
            return true;
        } 
            
        if (mat[0][i] != ' ' && mat[0][i] == mat[1][i] && mat[1][i] == mat[2][i]){
            winflag[3+i]=1;
            return true;
        }
    }
    
    // diagonals check
    if (mat[0][0] != ' ' && mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2]){
        winflag[6]=1;
        return true;
    }
    
    if (mat[2][0] != ' ' && mat[2][0] == mat[1][1] && mat[1][1] == mat[0][2]){
        winflag[7]=1;
        return true;
    }

    return false;
}

//Confetti class member declaration
void Confetti::renderCelebration(const float& timeStarted, const bool& turn){
    const float timeNow = GetTime();
    float interval = 0.05;
    bool drift = fmod(timeNow, interval*2) < interval;

    if(turn){
        DrawTexture(blueconfetti, (drift)? 0 : 20, (int)((timeNow - timeStarted)*300), WHITE);
        return;
    }

    DrawTexture(redconfetti, (drift)? 0 : 20, (int)((timeNow - timeStarted)*300), WHITE);
}

void handleEndGame(bool& win, const bool& turn, vector<bool>& winflag, const int& turncount, const vector<vector<char>>& mat){
    if(turncount<=9 && winvalidation(mat, winflag)){
        PlaySound(victoryjingle);
        win=1; //else it is a draw
    }

    Grid gridobj;
    Token tokenobj;

    gameover=1; //program exit flag

    float interval = 1.0;
    float timeElapsed;
    bool shouldDraw;

    float timeStarted = GetTime();
    Confetti confettiobj;

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);

        gridobj.drawGrid();
        tokenobj.renderTokens(mat);

        if(win){ //won game
            //drawing the strikethrough line
            if(winflag[0])DrawRectangle(400,225, 480,5, GRAY);
            if(winflag[1])DrawRectangle(400,385, 480,5, GRAY);
            if(winflag[2])DrawRectangle(400,545, 480,5, GRAY);

            if(winflag[3])DrawRectangle(495,140, 5,480, GRAY);
            if(winflag[4])DrawRectangle(650,140, 5,480, GRAY);
            if(winflag[5])DrawRectangle(800,140, 5,480, GRAY);
            
            if(winflag[6])DrawRectanglePro({865,595, 5,615}, {0,0}, 136.0, GRAY);
            if(winflag[7])DrawRectanglePro({425,595, 5,615}, {0,0}, 226.0, GRAY);

            DrawTextEx(pixelfont, "PLAYER          WINS !", {420, 20}, 55, 0, WHITE);
            if(turn) DrawTextEx(pixelfont, "TWO", {595, 20}, 55, 0, BLUE);
            else DrawTextEx(pixelfont, "ONE", {610, 20}, 55, 0, RED);

            //drawing confetti
            if(GetTime() - timeStarted < 2) confettiobj.renderCelebration(timeStarted, turn);
        }

        else DrawTextEx(pixelfont, "DRAW MATCH. GGs !", {420, 20}, 55, 0, WHITE);

        timeElapsed = GetTime();
        shouldDraw = fmod(timeElapsed, interval * 2) < interval;
        if(shouldDraw) DrawTextEx(pixelfont, "press R to restart - press ENTER/ESC to exit", {265, 650}, 45, 0, WHITE);

        EndDrawing();

        if(IsKeyPressed(KEY_ENTER))return;
        else if(IsKeyPressed(KEY_R)){
            gameover=0;
            return;
        }
    }
}

void multiplayer() {
    int x = 0, y = 0, turncount = 0;
    bool win = 0, turn = 1;

    Cursor cursorobj;
    Grid gridobj;
    Token tokenobj;

    vector<bool>winflag(8, 0);
    vector<vector<char>> mat(3, vector<char>(3, ' '));

    while (!WindowShouldClose() && !gameover) {
        BeginDrawing();

        ClearBackground(BLACK);
        gridobj.drawGrid();

        DrawTextEx(pixelfont, "player       , make your move.", {330, 20}, 55, 0, WHITE);
        if(turn) DrawTextEx(pixelfont, "ONE", {475, 20}, 55, 0, RED); 
        else DrawTextEx(pixelfont, "TWO", {457, 20}, 55, 0, BLUE); 

        DrawTextEx(pixelfont, "--WASD to move, SPACE to place token--", {300, 650}, 45, 0, WHITE);

        cursorobj.updateCursor(x, y); //handling user input
        cursorobj.renderCursor(x,y); //rendering the cursor
        tokenobj.renderTokens(mat); //rendering the game state/placed tokens

        EndDrawing();

        if(IsKeyPressed(KEY_SPACE)){
            if(mat[y][x] == ' '){ //token placed
                mat[y][x] = (turn)? 'X' : 'O'; 
                turn = !turn;
                ++turncount;
                PlaySound(token_placed);
            }
            else PlaySound(invalid_move); //invalid move
        }

        if (winvalidation(mat, winflag) || turncount==9) {  //game over
            handleEndGame(win, turn, winflag, turncount, mat);
            return;
        }
    }
}