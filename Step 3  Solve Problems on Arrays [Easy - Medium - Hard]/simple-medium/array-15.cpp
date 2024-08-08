#include<bits/stdc++.h>
using namespace std;

// rotate matrix/image by 90degree

void rev(vector<vector<int>> &matrix, int row_no, int n){
    int start = 0;
    int end = n - 1;
    while(start < end){
        swap(matrix[row_no][start], matrix[row_no][end]);
        start++;
        end--;
    }
}

vector<vector<int>> rotate_matrix(vector<vector<int>> &matrix, int row, int col){
    // brute
    /* vector<vector<int>> ans(row, vector<int>(col, 0));

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            ans[j][row - 1 - i] = matrix[i][j];
        }
    }
    return ans;

    // TC : O(n^2)
    // SC : O(n^2) */


    // optimal    (consider n = row , m = col)
    // 1.transpose
    for(int i = 0; i < row - 1; i++){   // TC : O(n/2 x m/2)
        for(int j = i + 1; j < col; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // 2.reverse each row
    for(int i = 0; i < row; i++){      //TC : O(n x n/2) 
        rev(matrix, i, row);
    }
    return matrix;

    // Time Complexity: O(N*N) + O(N*N).One O(N*N) is for transposing the matrix and the other is for reversing the matrix.
    // Space Complexity: O(1).
}


int main()
{
    vector<vector<int>> matrix = {{1, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 1}};
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> ans = rotate_matrix(matrix, row, col);

    cout << "The Final matrix is: \n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}