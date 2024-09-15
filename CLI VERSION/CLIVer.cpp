#include<bits/stdc++.h>
using namespace std;

void printMatrix(const vector<vector<char>>& mat){
    for (int i = 0; i < 3; ++i) {
        cout << " " << mat[i][0] << " | " << mat[i][1] << " | " << mat[i][2] << " \n";
        if (i < 2) { // print the horizontal separator between rows
            cout << "---|---|---\n";
        }
    }
}

bool moveValidation(const vector<vector<char>>& mat, int x, int y){
    if (x < 1 || x > 3 || y < 1 || y > 3) return false;
    else if (mat[x - 1][y - 1] != ' ') return false;

    return true;
}

bool winValidation(const vector<vector<char>>& mat){

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

void sessionStart(){
    int x, y, turncount=0;
    bool win = false, turn = true;
    vector<vector<char>> mat(3, vector<char>(3, ' '));

    while (!win) {
        system("cls");
        printMatrix(mat); // printing matrix state

        // input validation
        char player = (turn ? 'X' : 'O');
        cout << "Player " << player << ", enter the coordinates of your move (x y) :\n";
        cin >> x >> y;

        if(!moveValidation(mat, x, y)){ //move validation check
            cout<<"\n\nINVALID MOVE CHOICE. PLEASE TRY AGAIN.\n\n";
            system("PAUSE");
            continue;
        }

        mat[x - 1][y - 1] = player;
        turncount++;

        // win validation check
        if (winValidation(mat)) {
            win = true;
            system("cls");
            printMatrix(mat);
            cout << "\n\nGAME OVER. PLAYER " << player << " WINS.\n\n-----------------------------------------------------------------------------------------\n";
        }

        else if(turncount == 9){
            cout<<"\n\nDRAW. NO ONE WINS.\n\n";
            return;
        }

        turn = !turn; // Swap turn
    }
}

int main(){
    int choice;
    bool run = true;

    cout << "Welcome to Bitwise-XO !\n\n";

    while (run) {
        cout << "Enter your desired action:\n1. Start New Game\n2. Exit\n";
        cin >> choice;


        switch (choice) {
            case 1:
                system("cls");
                sessionStart();
                break;
            
            case 2:
                cout << "Thanks for Playing !";
                run = false;
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
