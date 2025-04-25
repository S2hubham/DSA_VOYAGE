#include<bits/stdc++.h>
using namespace std;


// non overlapping intervals
bool comp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}


int func(vector<vector<int>> arr){
    // sort(arr.begin(), arr.end(), comp);  // in leetode this doesnt as refer book
    sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    });

    int n = arr.size(), freetime = arr[0][1], cnt = 1;
    for(int i = 1; i < n; i++){
        if(arr[i][0] >= freetime){  // this is the only change
            cnt++;
            freetime = arr[i][1];
        }
    }
    return (n - cnt);

    // TC : O(nlogn + n)
    // SC : O(1)
}


int main(){
    vector<vector<int>> intervals = {  // 2
        {0, 5},
        {3, 4},
        {1, 2},
        {5, 9},
        {5, 7},
        {7, 9}
    };

    vector<vector<int>> intervals1 = { // 1
        {1, 2},
        {2, 3},
        {3, 4},
        {1, 3}
    };
    cout<<"Mini no. of intervals that nned to be removed : "<<func(intervals1);
    return 0;
}