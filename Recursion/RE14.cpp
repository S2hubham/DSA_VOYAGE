#include <bits/stdc++.h>
using namespace std;

// combination sum 2

// brute force
/* void func(vector<int> arr, vector<int> &temp, set<vector<int>> &ansSet, int target, int i, int n){
    // base case
    if(target == 0 || i == n){
        if(target == 0){
            sort(temp.begin(), temp.end());
            ansSet.insert(temp);
            return;
        }
        return;
    }

    if(arr[i] <= target){
        temp.push_back(arr[i]);
        func(arr, temp, ansSet, target-arr[i], i+1, n);
        temp.pop_back();
    }
    func(arr, temp, ansSet, target, i+1, n);

    // TC : O(2^t * klogn)  logn is extra due to set insertion
    // SC : O(n)
} 


vector<vector<int>> comb_sum(vector<int> arr, int target){
    set<vector<int>> ansSet;
    vector<int> temp;
    func(arr, temp, ansSet, target, 0, arr.size());
    vector<vector<int>> ans(ansSet.begin(), ansSet.end());
    return ans;
}
*/


// better
void func(vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans, int target, int ind){
    // base case
    if(target == 0){
        ans.push_back(temp);
        return;
    }

    for(int i = ind; i < arr.size(); i++){
        if(i > ind && arr[i] == arr[i-1]) continue;

        if(arr[i] > target) break;

        temp.push_back(arr[i]);
        func(arr, temp, ans, target-arr[i], i+1);
        temp.pop_back();
    }

    // TC : O(2^t * k) + O(nlogn)
    // SC : O(m * k)

    // m = unique combos, k = temp avg size, t = height of tree
}


vector<vector<int>> comb_sum(vector<int> &arr, int target){
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> temp;
    func(arr, temp, ans, target, 0);
    return ans;
}



int main()
{
    vector<int> arr = {1, 1, 1, 2, 2};
    vector<vector<int>> ans = comb_sum(arr, 4);

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

func(arr=[1, 1, 1, 2, 2], temp=[], target=4, ind=0)
    ├── Include 1 (arr[0])
    │   func(arr, temp=[1], target=3, ind=1)
    │       ├── Include 1 (arr[1])
    │       │   func(arr, temp=[1, 1], target=2, ind=2)
    │       │       ├── Include 1 (arr[2])
    │       │       │   func(arr, temp=[1, 1, 1], target=1, ind=3)
    │       │       │       ├── Skip (arr[3]=2 > target=1) → Backtrack
    │       │       │       └── End (ind=5) → Backtrack
    │       │       └── Include 2 (arr[3])
    │       │           func(arr, temp=[1, 1, 2], target=0, ind=4)
    │       │           └── Found Combination: [1, 1, 2] → Backtrack
    │       └── Skip 1 (arr[2] is duplicate) → Backtrack
    │           ├── Include 2 (arr[3])
    │           │   func(arr, temp=[1, 2], target=1, ind=4)
    │           │       ├── Skip (arr[4]=2 > target=1) → Backtrack
    │           │       └── End (ind=5) → Backtrack
    │           └── End → Backtrack
    └── Skip 1 (arr[1] is duplicate) → Backtrack
        ├── Include 2 (arr[3])
        │   func(arr, temp=[2], target=2, ind=4)
        │       ├── Include 2 (arr[4])
        │       │   func(arr, temp=[2, 2], target=0, ind=5)
        │       │   └── Found Combination: [2, 2] → Backtrack
        │       └── End → Backtrack
        └── End → Backtrack


 */