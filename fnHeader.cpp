#include "fnHeader.h"

bool menuexit = 0, gameover = 0, mode = 1;
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

void multiplayer() {
    int x = 0, y = 0, turncount = 0;
    bool win = 0, turn = 1;

    vector<bool>winflag(8, 0);
    vector<vector<char>> mat(3, vector<char>(3, ' '));

    while (!WindowShouldClose() && !gameover) {
        inputChecker(x, y);

        if(IsKeyPressed(KEY_SPACE) && mat[y][x] == ' '){ // placing token
            mat[y][x] = (turn)? 'X' : 'O'; 
            turn = !turn;
            ++turncount;
        }

        if (winvalidation(mat, winflag) || turncount==9) {  //win validation
            //possibly divvy this part up into a function ? -----------------------------
            if(turncount<9)win=1; //else it is a draw

            gameover=1; //program exit flag

            while(!WindowShouldClose()){
                BeginDrawing();

                if(win){ //won game
                    DrawTexture(gridtexture, 0, 0, WHITE);
                    renderstate(mat);

                    //drawing the strikethrough line
                    if(winflag[0])DrawRectangle(400,225, 480,5, GRAY);
                    if(winflag[1])DrawRectangle(400,385, 480,5, GRAY);
                    if(winflag[2])DrawRectangle(400,545, 480,5, GRAY);

                    if(winflag[3])DrawRectangle(495,140, 5,480, GRAY);
                    if(winflag[4])DrawRectangle(650,140, 5,480, GRAY);
                    if(winflag[5])DrawRectangle(800,140, 5,480, GRAY);
                    
                    if(winflag[6]){
                        Rectangle strike = {865,595, 5,615};
                        Vector2 origin = {0,0};
                        
                        DrawRectanglePro(strike, origin, 136.0, GRAY);
                    }
                    if(winflag[7]){
                        Rectangle strike = {425,595, 5,615};
                        Vector2 origin = {0,0};
                        
                        DrawRectanglePro(strike, origin, 226.0, GRAY);
                    }
                }

                else{ //draw game
                    DrawTexture(gridtexture, 0, 0, WHITE);
                    renderstate(mat);
                }

                EndDrawing();

                if(IsKeyPressed(KEY_ENTER))return;
                else if(IsKeyPressed(KEY_R)){
                    gameover=0;
                    return;
                }
            }
        }
        
        BeginDrawing();

        ClearBackground(BLACK);
        DrawTexture(gridtexture, 0, 0, WHITE); //drawing the grid

        DrawTexture(gameplay_text1_texture, 250, 40, WHITE);
        if(turn) DrawTexture(p1icon_texture, 470, 35, WHITE); 
        else DrawTexture(p2icon_texture, 470, 35, WHITE);

        rendercursor(x,y); //rendering the cursor
        renderstate(mat); //rendering the game state/placed tokens

        EndDrawing();
    }
}