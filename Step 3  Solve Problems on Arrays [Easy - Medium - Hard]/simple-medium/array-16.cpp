#include<bits/stdc++.h>
using namespace std;

// spiral traversal
vector<int> spiral_matrix(vector<vector<int>> matrix, int row, int col){
    vector<int> ans;
    int left = 0, right = col - 1;
    int top = 0, bottom = row - 1;

    while(left <= right && top <= bottom){
        // consider case of single row and with only two rows

        // left(top) to right(top)
        for(int i = left; i <= right; i++){
            ans.push_back(matrix[top][i]);
        }
        top++;

        // top(right) to bottom(right)
        for(int i = top; i <= bottom; i++){
            ans.push_back(matrix[i][right]);
        }
        right--;

        if(top <= bottom){
            // right(bottom) to left(bottom)
            for(int i = right; i >= left; i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if(left <= right){
            // bottom(left) to top(left)
            for(int i = bottom; i >= top; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;

}



int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4, 5, 6}, {20, 21, 22, 23, 24, 7}, {19, 32, 33, 34, 25, 8}, {18, 31, 36, 35, 26, 9}, {17, 30, 29, 28, 27, 10}, {16, 15, 14, 13, 12, 11}};
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> ans = spiral_matrix(matrix, row, col);

    cout << "The Final matrix is: \n";
    for (auto it : ans) {
        cout << it << " ";
    }
    return 0;
}