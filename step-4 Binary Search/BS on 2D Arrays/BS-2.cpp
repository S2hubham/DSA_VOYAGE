#include <bits/stdc++.h>
using namespace std;

// Search in a 2 D matrix
vector<int> search(vector<vector<int>> arr, int k){
    /* int row_cnt = arr.size();
    int col_cnt = arr[0].size();
    for(int i = 0; i < row_cnt; i++){
        if(arr[i][0] <= k && k <= arr[i][col_cnt-1]){
            int low = 0, high = col_cnt;
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


    // Better (by flattening 2D to 1D)
    int row_cnt = arr.size();
    int col_cnt = arr[0].size();
    int low = 0, high = (row_cnt*col_cnt - 1);
    while(low <= high){
        int mid = low + (high - low)/2;
        int row = mid / col_cnt;
        int col = mid % col_cnt;
        if(arr[row][col] == k){
            return {row+1, col+1};
        }
        else if(arr[row][col] < k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return {};

    // TC : O(log (n x m))
    // SC : O(1)
}

int main()
{
    vector<vector<int>> arr = {
        {3, 4, 7, 9},
        {12, 13, 16, 18},
        {20, 21, 23, 29}
    };
    vector<int> ans = search(arr, 29);
    if(ans.size() == 0){
        cout<<"Not found!!";
    }
    else{
        cout<<"found at row : " << ans[0] << "\nfound at col : " << ans [1];
    }
}