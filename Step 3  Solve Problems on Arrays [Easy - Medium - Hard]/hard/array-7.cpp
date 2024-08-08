#include <bits/stdc++.h>
using namespace std;

// merge overlapping intervals
void merge_overlap_interval(vector<vector<int>> arr, int n)
{
    // brute
    /* sort(arr.begin(), arr.end());  //TC : O(n logn)
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++){
        int start = arr[i][0];
        int end = arr[i][1];

        // for next/new i
        // check if arr[i] is already overlapping
        if(!ans.empty() && end <= ans.back()[1]){
            continue;
        }

        for(int j = i+1; j < n; j++){   //TC : O(n)
            if(arr[j][0] <= end){
                end = max(end, arr[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start, end});
    }
    for(auto it : ans){
        for(auto ele : it){
            cout<<ele<<" ";
        }
        cout<<"\n";
    } */
    // TC : O(nlogn) + O(2n)
    // SC : O(n)

    // optimal
    /* sort(arr.begin(), arr.end()); // TC : O(n logn)
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        // condition for new pair
        // Check if array is empty OR check if current idx start is > ans back last
        if (ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        // check for new replacable end
        else
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "\n";
    } */
    // TC : O(n logn) + O(n)
    // SC : O(n)
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 9}, {9, 11}, {8, 10}, {2, 4}, {15, 18}, {16, 17}};
    int n = arr.size();
    merge_overlap_interval(arr, n);
    return 0;
}