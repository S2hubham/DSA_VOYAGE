#include <bits/stdc++.h>
using namespace std;

int find_row(vector<vector<int>> arr, int mid){
    int index = -1, max_ele = INT_MIN;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i][mid] > max_ele){
            max_ele = arr[i][mid];
            index = i;
        }
    }
    return index;
}

// Peak in a 2D matrix
vector<int> peak(vector<vector<int>> arr){
    // better 

    int row_cnt = arr.size(), col_cnt = arr[0].size();
    int low = 0, high = col_cnt-1;
    while(low <= high){
        int mid = low + (high - low)/2;

        int row = find_row(arr, mid);

        int col_max = arr[row][mid];

        int left = mid-1 >= 0 ? arr[row][mid-1] : -1;
        int right = mid+1 < col_cnt ? arr[row][mid+1] : -1;

        if(left < col_max  && col_max > right){
            return {row+1, mid+1};
        }
        else if(left > col_max){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return {};

    // TC : O(n log m)
}

int main()
{
    vector<vector<int>> arr = {
        {4, 2, 5, 1, 4, 5},
        {2, 9, 3, 2, 3, 2},
        {1, 7, 6, 0, 1, 3},
        {3, 6, 2, 3, 7, 2}
    };
    vector<int> ans = peak(arr);
    if(ans.size() == 0){
        cout<<"Not found!!";
    }
    else{
        cout<<"Peak found at row : " << ans[0] << "\nfound at col : " << ans [1];
    }
}