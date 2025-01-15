#include <bits/stdc++.h>
using namespace std;

// combination sum
void func(vector<int> arr, vector<int> &temp, vector<vector<int>> &ans, int target, int i, int n){
    // base case
    if(target == 0 ||i == n){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        return;
    }

    // pick condition
    if(target >= arr[i]){
        temp.push_back(arr[i]);
        func(arr, temp, ans, target-arr[i], i, n);
        temp.pop_back();
    }
    // non pick condition
    func(arr, temp, ans, target, i+1, n);    
}

vector<vector<int>> comb_sum(vector<int> arr, int target){
    vector<vector<int>> ans;
    vector<int> temp;
    func(arr, temp, ans, target, 0, arr.size());
    return ans;
}

int main()
{
    vector<int> arr = {2, 3, 6, 7};
    vector<vector<int>> ans = comb_sum(arr, 7);

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