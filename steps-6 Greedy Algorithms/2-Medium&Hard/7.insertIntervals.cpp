#include<bits/stdc++.h>
using namespace std;


// insert intervals
vector<vector<int>> func(vector<vector<int>> intervals, vector<int> interval){
    int n = intervals.size(), i = 0;
    vector<vector<int>> ans;
    // left valid part
    while(i < n && intervals[i][1] < interval[0]){
        ans.push_back(intervals[i]);
        i++;
    }

    // middle overlapping part
    while(i < n && intervals[i][0] <= interval[1]){
        interval[0] = min(interval[0], intervals[i][0]);
        interval[1] = max(interval[1], intervals[i][1]);
        i++;
    }
    ans.push_back(interval);

    // right valid part
    while(i < n){
        ans.push_back(intervals[i]);
        i++;
    }

    return ans;
}


int main(){
    vector<vector<int>> intervals = {  
        {1, 2},
        {3, 4},
        {5, 7},
        {8, 10},
        {12, 16}
    };

    vector<int> interval = {6, 8};

    vector<vector<int>> intervals1 = {  
        {1, 3},
        {6, 9}
    };

    vector<int> interval1 = {2, 5};

    vector<vector<int>> ans = func(intervals, interval);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[0].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}