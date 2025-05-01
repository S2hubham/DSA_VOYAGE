#include<bits/stdc++.h>
using namespace std;

// merge intervals
bool comp(vector<int> &a, vector<int> &b){
    return a[0] < b[0];
}

void func(vector<vector<int>> arr){
    // brute force
    sort(arr.begin(), arr.end(), comp);

    vector<vector<int>> ans;
    int j = 0;
    ans.push_back(arr[j]);
    for(int i = 1; i < arr.size(); i++){
        if(arr[i][0] <= ans[j][1]){
            ans[j][1] = max(ans[j][1], arr[i][1]);
        }
        else{
            ans.push_back(arr[i]);
            j++;
        }
    }

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return;

    // TC : O(nlogn + n)
    // SC : O(n)
}


int main(){
    vector<vector<int>> intervals = {
        {1, 3},
        {8, 10},
        {2, 6}, 
        {9, 9},
        {15, 18}
    };

    vector<vector<int>> intervals1 = {
        {1, 4},
        {4, 5}
    };

    func(intervals);
    return 0;
}