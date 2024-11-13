#include <bits/stdc++.h>
using namespace std;


int find(vector<vector<int>> arr, int x){
    int max_cnt = 0;
    int row_cnt = arr.size(), col_cnt = arr[0].size();
    for(int i = 0; i < row_cnt; i++){
        int low = 0, high = col_cnt-1;
        int cnt = col_cnt;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[i][mid] > x){
                cnt = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        max_cnt += cnt;
    }
    return max_cnt;
}


// find a median in row-wise 2D matrix
int median(vector<vector<int>> arr){
    // brute
    /* vector<int> temp;
    int row_cnt = arr.size(), col_cnt = arr[0].size();
    for(int i = 0; i < row_cnt; i++){   //TC : O(n*m)
        for(int j = 0; j < col_cnt; j++){
            temp.push_back(arr[i][j]);
        }
    }

    sort(temp.begin(), temp.end());    // TC : O(n*m log(n*m))

    int median = (row_cnt * col_cnt) / 2;

    return temp[median]; */

    // TC : O(n*m log(n*m))
    // SC : O(n*m)


    // better
    int row_cnt = arr.size(), col_cnt = arr[0].size();
    // find median index
    int medianIdx = (row_cnt*col_cnt)/2;

    // set the range
    int low = INT_MAX, high = INT_MIN;
    for(int i = 0; i < row_cnt; i++){
        low = min(low, arr[i][0]);
        high = max(high, arr[i][col_cnt-1]);
    }
    
    // TC : O(log (10^9)) as the values can be as big as 10^9
    while(low <= high){
        int mid = low + (high - low)/2;
        // cout<<"mid "<<mid<<endl;
        int smallerEquals = find(arr, mid);  // TC : O(R log C)
        // cout<<smallerEquals<<endl;

        if(smallerEquals < medianIdx){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;

    // TC : O(log (10^9) * R log C)
}

int main()
{
    vector<vector<int>> arr = {
        {1, 2, 3, 4, 5},
        {8, 9, 11, 12, 13},
        {21, 23, 25, 27, 29}
    };
    cout<<"Median is : " << median(arr);
}