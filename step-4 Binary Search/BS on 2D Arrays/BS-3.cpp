#include <bits/stdc++.h>
using namespace std;

// Search in a row and column wise sorted matrix

vector<int> search(vector<vector<int>> arr, int k){
    // better
    /* int row_cnt = arr.size(), col_cnt = arr[0].size();
    for(int i = 0; i < row_cnt; i++){
        if(arr[i][0] <= k && k <= arr[i][col_cnt-1]){
            int low = 0, high = col_cnt-1;
            while(low <= high){
                int mid = low + (high - low)/2;
                if(arr[i][mid] == k){
                    return {i+1, mid+1};
                }
                else if(arr[i][mid] < k){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
    }
    return {}; */

    // TC : O(n log m)
    // SC : O(1)


    // best
    // starting point is top-right corner
    int row_cnt = arr.size(), col_cnt = arr[0].size();
    int row = 0, col = col_cnt-1;
    while(row < row_cnt && col >= 0){
        if(arr[row][col] == k){
            return {row+1, col+1};
        }
        else if(arr[row][col] < k){
            row++;
        }
        else{
            col--;
        }
    }
    return {};

    // OR

    // starting point is bottom-left corner
    int row_cnt = arr.size(), col_cnt = arr[0].size();
    int row = row_cnt-1, col = 0;
    while(row < row_cnt && col >= 0){
        if(arr[row][col] == k){
            return {row+1, col+1};
        }
        else if(arr[row][col] < k){
            col++;
        }
        else{
            row--;
        }
    }
    return {};

    // TC : O(n + m)
    // SC : O(1)
}



int main()
{
    vector<vector<int>> arr = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    vector<int> ans = search(arr, 15);
    if(ans.size() == 0){
        cout<<"Not found!!";
    }
    else{
        cout<<"found at row : " << ans[0] << "\nfound at col : " << ans [1];
    }
}