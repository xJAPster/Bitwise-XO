#include<bits/stdc++.h>
#include<raylib.h>
using namespace std;

//declaration space
bool menuexit=0, gameover=0, mode=1;
Image grid;
Texture2D gridtexture;

void menuscreen();
void multiplayer();
void endscreen();

int main(){
    const int width = 1280;
    const int height = 720;

    SetTargetFPS(60);
    InitWindow(width, height, "Bitwise-XO");

    while(!WindowShouldClose()){
        if(!menuexit)menuscreen();

        if(gameover)endscreen();
        if(gameover)break; //end game
        
        if(mode)multiplayer();

    }

    return 0;
}

void menuscreen(){
    while(!WindowShouldClose() && !menuexit){
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("MENU SCREEN", 640, 360, 30, WHITE); //placeholder
        EndDrawing();

        if(IsKeyPressed(KEY_ENTER)){
            menuexit=1;
            ClearBackground(BLACK);
        }
    }
}

inline void inputChecker(int& x, int& y){
    if(IsKeyPressed(KEY_W) && x>0)--x;
        
    if(IsKeyPressed(KEY_S) && x<2)++x;
        
    if(IsKeyPressed(KEY_A) && y>0)--y;

    if(IsKeyPressed(KEY_D) && y<2)++y;
}

void multiplayer(){
    int x=0, y=0, turncount=0;
    bool win = 0, turn = 1;
    vector<vector<char>> mat(3, vector<char>(3, ' '));

    Image grid = LoadImage("assets/grid.png");
    Texture2D gridtexture = LoadTextureFromImage(grid);
    while(!WindowShouldClose() && !win){
        inputChecker(x,y);
        //function to modify matrix and place + render the placed token

        if(IsKeyPressed(KEY_ENTER) && mat[x][y]==' '){
            mat[x][y] = (turn)? 'X' : '0';
            turn = !turn;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(gridtexture, 0, 0, WHITE);
        // const string s = "X:"+to_string(x)+" , Y:"+to_string(y);
        // const char* text = s.c_str();
        // DrawText(text, 640, 360, 30, WHITE);

        EndDrawing();
        
        if(x==2 && y==2){
            win=1;
            gameover=1;
        }
    }
}

void endscreen(){
    while(!WindowShouldClose() && gameover){
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("JOEVER SCREEN", 640, 360, 30, WHITE); //placeholder
        EndDrawing();

        if(IsKeyPressed(KEY_ENTER))return;
    }
}