#include<bits/stdc++.h>
using namespace std;

// set matrix to zeros

// brute
/* void mark_row(int arr[][4], int row, int col){  //TC : O(m)
    for(int i = 0; i < col; i++){
        if(arr[row][i] != 0){
            arr[row][i] = -1;
        }
    }
    return;
}

void mark_col(int arr[][4], int row, int col){   //TC : O(n)
    for(int i = 0; i < row; i++){
        if(arr[i][col] != 0){
            arr[i][col] = -1;
        }
    }
    return;
}

void Set_Matrix_Zeroes(int arr[][4], int row, int col){   //TC : O(n x m)
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(arr[i][j] == 0){
                mark_row(arr, i, col);
                mark_col(arr, row, j);
            }
        }
    }

    for(int i = 0; i < row; i++){     //TC : O(n x m)
        for(int j = 0; j < col; j++){
            if(arr[i][j] == -1){
                arr[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout<<arr[i][j]<<" ";
        }
    }

    //TC : O(n x m) x (O(n) + O(m)) + O(n x m)
} 

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    int arr[4][4];
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    Set_Matrix_Zeroes(arr, n, m);
    return 0;
}
*/



// better
/* vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    int row[n] = {0}; // row array
    int col[m] = {0}; // col array

    // Traverse the matrix:
    for (int i = 0; i < n; i++) {        //TC : O(n x m)
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark ith index of row wih 1:
                row[i] = 1;

                // mark jth index of col wih 1:
                col[j] = 1;
            }
        }
    }

    // Finally, mark all (i, j) as 0
    // if row[i] or col[j] is marked with 1.
    for (int i = 0; i < n; i++) {    //TC : O(n x m)
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;


    //TC : O(n x m) + O(n x m)
    //SC : O(n) + O(m)
}

 */


// optimal
vector<vector<int>> zeroMatrix(vector<vector<int>> &arr, int row, int col) {
    // mark zeros for row and col
    int col0 = 1;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(arr[i][j] == 0){
                // for row
                arr[i][0] = 0;
                // for col
                // check if it is already zero then only mark it zero
                if(j != 0){
                    arr[0][j] = 0;
                }
                //check if it is not the first row element i.e. col0
                else{
                    col0 = 0;
                }
            }
        }
    }

    //traverse and mark all to zeros
    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            // check only for 1's 
            if(arr[i][j] != 0){
                //check the row_mark and col_mark for 1 -> 0
                if(arr[0][j] == 0 || arr[i][0] == 0){
                    arr[i][j] = 0;
                }
            }
        }
    }

    // first check the row_mark if 0 the 
    if(arr[0][0] == 0){
        for(int j = 0; j < col; j++){
            arr[0][j] = 0;
        }
    }
    if(col0 == 0){
        for(int i = 0; i < row; i++){
            arr[i][0] = 0;
        }
    }

    return arr;
}


int main()
{
    vector<vector<int>> matrix = {{1, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is: \n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}