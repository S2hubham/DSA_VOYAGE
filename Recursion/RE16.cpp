#include <bits/stdc++.h>
using namespace std;

// subset sum 2

// brute force  (using set to keep unique lists only)
/* void func(vector<int> arr, vector<int> &temp, set<vector<int>> &ansSet, int i, int n){
    // base case
    if (i == n) {
        ansSet.insert(temp);
        return;
    }

    // pick
    temp.push_back(arr[i]);
    func(arr, temp, ansSet, i+1, n);
    temp.pop_back();
    // non pick
    func(arr, temp, ansSet, i+1, n);
} 


vector<vector<int>> subset_sum_2(vector<int> arr){
    set<vector<int>> ansSet;
    vector<int> temp;
    // sort(arr.begin(), arr.end()); 
    func(arr, temp, ansSet, 0, arr.size());  
    vector<vector<int>> ans(ansSet.begin(), ansSet.end());
    return ans;

    // TC : O(2^n * nlog2^n) == O(2^n * n^2)
    // SC : O(n* 2^n)
    // this approach requires string in set and then again moving it to list
}  */



// better force
void func(vector<int> arr, vector<int> &temp, vector<vector<int>> &ans, int idx, int n){
    // base case
    ans.push_back(temp);
    for(int i = idx; i < n; i++){
        // non pick 
        if(i > idx && arr[i] == arr[i-1]) continue;
        temp.push_back(arr[i]);
        func(arr, temp, ans, i+1, n);
        temp.pop_back();
    }
} 


vector<vector<int>> subset_sum_2(vector<int> arr){
    vector<vector<int>> ans;
    vector<int> temp;
    func(arr, temp, ans, 0, arr.size());   
    return ans;

    // TC : O(2^n * n)
    // SC : O(2^n * n)
}



int main()
{
    vector<int> arr = {1, 2, 2};
    vector<vector<int>> ans = subset_sum_2(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i].empty())
        {                 
            cout << "{}"; 
        }
        else
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}



// recursion tree
/* 

 */