#include <bits/stdc++.h>
using namespace std;

// sudoko solver
bool isValid(vector<vector<char>> &board, int row, int col, char c){
    for(int i = 0; i < 9; i++){
        // check for col
        if(board[row][i] == c)    return false;
        // check for row
        if(board[i][col] == c)    return false;
        // check for 3x3 matrix
        if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == c)    return false;
    }
    return true;
}

bool solve(vector<vector<char>> &board){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] == '.'){
                for(char c = '1'; c <= '9'; c++){
                    if(isValid(board, i, j, c)){
                        board[i][j] = c;
                        
                        if(solve(board) == true){
                            return true;
                        }
                        else{
                            board[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void sudoko() {
    // vector<char> r1 = {'5', '3', '.', '.', '7', '.', '.', '.', '.'};
    // vector<char> r2 = {'6', '.', '.', '1', '9', '5', '.', '.', '.'};
    // vector<char> r3 = {'.', '9', '8', '.', '.', '.', '.', '6', '.'};
    // vector<char> r4 = {'8', '.', '.', '.', '6', '.', '.', '.', '3'};
    // vector<char> r5 = {'4', '.', '.', '8', '.', '3', '.', '.', '1'};
    // vector<char> r6 = {'7', '.', '.', '.', '2', '.', '.', '.', '6'};
    // vector<char> r7 = {'.', '6', '.', '.', '.', '.', '2', '8', '.'};
    // vector<char> r8 = {'.', '.', '.', '4', '1', '9', '.', '.', '5'};
    // vector<char> r9 = {'.', '.', '.', '.', '8', '.', '.', '7', '9'};
    // vector<vector<char>> validboard = {r1, r2, r3, r4, r5, r6, r7, r8, r9};


    // invalid board
    vector<char> r1 = {'5', '3', '5', '.', '7', '.', '.', '.', '.'}; // Duplicate '5' in row 1
    vector<char> r2 = {'6', '.', '.', '1', '9', '5', '.', '.', '.'};
    vector<char> r3 = {'.', '9', '8', '.', '.', '.', '.', '6', '.'};
    vector<char> r4 = {'8', '.', '.', '.', '6', '.', '.', '.', '3'};
    vector<char> r5 = {'4', '.', '.', '8', '.', '3', '.', '.', '1'};
    vector<char> r6 = {'7', '.', '.', '.', '2', '.', '.', '.', '6'};
    vector<char> r7 = {'.', '6', '.', '.', '.', '.', '2', '8', '.'};
    vector<char> r8 = {'.', '.', '.', '4', '1', '9', '.', '.', '5'};
    vector<char> r9 = {'.', '.', '.', '.', '8', '.', '.', '7', '9'};
    vector<vector<char>> board = {r1, r2, r3, r4, r5, r6, r7, r8, r9};



    if(solve(board)){
        cout<<"True. Sudoko is solved";
        return;
    }
    cout<<"False. Sudoko is not solved";
    return;
} 

int main() {
    sudoko();
    return 0;
} 