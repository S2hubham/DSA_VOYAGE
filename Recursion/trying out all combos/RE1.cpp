#include <bits/stdc++.h>
using namespace std;

// NQueens

// brute  
/* bool isSafe(int row, int col, vector<string> &board, int n){
    int duprow = row;
    int dupcol = col;

    // check for upper left diagonal
    while(row >= 0 && col >= 0){        // TC : O(n)
        if(board[row][col] == 'Q')  return false;
        row--;
        col--;
    }

    // check for left col
    row = duprow;
    col = dupcol;
    while(col >= 0){                   // TC : O(n)
        if(board[row][col] == 'Q')  return false;
        col--;
    }

    // check for lower left diagonal
    row = duprow;
    col = dupcol;
    while(row < n && col >= 0){      // TC : O(n)
        if(board[row][col] == 'Q')  return false;
        row++;
        col--;
    }

    return true;
}

void func(vector<string> &board, vector<vector<string>> &ans, int col, int n){
    // base case
    if(col == n){
        ans.push_back(board);      //SC : O(n^2)
        return;
    }

    for(int row = 0; row < n; row++){        // TC : O(n)
        if(isSafe(row, col, board, n)){      // TC : O(n)
            board[row][col] = 'Q';
            func(board, ans, col+1, n);
            board[row][col] = '.';
        } 
    }

    // TC : O(n!) 
    // However, due to the pruning of invalid configurations in the backtracking algorithm, the practical complexity is much lower. The exact complexity depends on n but is typically bounded by O(n!), which represents the permutations of rows for placing queens.
    // SC : O(n! * n^2)
    // The ans vector stores all solutions. In the worst case, there are n! solutions, each requiring O(n2) space. Thus, the overall space complexity is: O(n2 -F n -F n2 x n!) O(n2 x n!)
}

vector<vector<string>> NQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string str(n, '.');
    for(int i = 0; i < n; i++){    
        board[i] = str;
    }
    func(board, ans, 0, n);
    return ans;


    // TC : O()
    // SC : O()
}  */





// better   (hashing)
void func(vector<string> &board, vector<vector<string>> &ans, int col, vector<int> leftcol, vector<int> upperdiag, vector<int> lowerdiag, int n){
    // base case
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row = 0; row < n; row++){       
        if(leftcol[row] == 0 && upperdiag[row+col] == 0 && lowerdiag[(n-1)+(col-row)] == 0){
            board[row][col] = 'Q';
            leftcol[row] = 1;
            upperdiag[row+col] = 1;
            lowerdiag[(n-1)+(col-row)] = 1;

            func(board, ans, col+1, leftcol, upperdiag, lowerdiag, n);

            board[row][col] = '.';
            leftcol[row] = 0;
            upperdiag[row+col] = 0;
            lowerdiag[(n-1)+(col-row)] = 0;
        }
    }

}

vector<vector<string>> NQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    vector<int> leftcol(n);
    vector<int> upperdiag(2*n-1, 0);
    vector<int> lowerdiag(2*n-1, 0);
    string str(n, '.');
    for(int i = 0; i < n; i++){    
        board[i] = str;
    }
    func(board, ans, 0, leftcol, upperdiag, lowerdiag, n);
    return ans;

    /* Thus, the total time complexity is approximately O(n!) in the worst case, where:
    • The first queen has n options,
    • The second queen has n — 1 options,
    • The third queen has n — 2 options, and so on.
    Time Complexity: O(n!)
    
    • The ans vector stores all solutions. In the worst case, there are n! solutions, each requiring O(n^2) space.
    Thus, the total space complexity is:
    O(n^2 x n!) */
    
} 

int main() {
    int n = 4; 
    vector<vector<string>> ans = NQueens(n);

    for (int i = 0; i < ans.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
} 