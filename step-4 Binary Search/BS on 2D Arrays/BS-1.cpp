#include <bits/stdc++.h>
using namespace std;


// Find the row with maximum number of 1's
int max_ones(vector<vector<int>> arr){
    // brute force
    /* int row_cnt = arr.size();
    int col_cnt = arr[0].size();
    int row = -1, max_cnt = 0;
    for(int i = 0; i < row_cnt; i++){
        int cnt = 0;
        for(int j = 0; j < col_cnt; j++){
            if(arr[i][j] == 1){
                cnt++;
            }
        }
        if(max_cnt < cnt){
            max_cnt = cnt;
            row = i;
        }
    }
    return row; */

    // TC : O(n x m)
    // SC : O(1)

    
    // better (instead of traversing whole array find first occ of 1 by BS and subtract it from col_cnt)
    int row_cnt = arr.size();
    int col_cnt = arr[0].size();
    int row = -1, max_cnt = 0;
    for(int i = 0; i < row_cnt; i++){
        int low = 0, high = col_cnt - 1;
        int x = col_cnt, cnt = 0;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(arr[i][mid] == 1){
                x = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        cnt = col_cnt - x;
        if(max_cnt < cnt){
            max_cnt = cnt;
            row = i;
        }
    }
    return row; 

    // TC : O(n log m)
    // SC : O(1)
}

int main()
{
    vector<vector<int>> arr = {
        {0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1}
    };
    cout << "Maximum ones are in row : " << max_ones(arr);
}
