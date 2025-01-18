#include <bits/stdc++.h>
using namespace std;

// combination sum 3

void func(vector<int> &temp, vector<vector<int>> &ans, int sum, int idx, int k, int n){
    // base case
    if(temp.size() == k){
        if(sum == n){
            ans.push_back(temp);
        }
        return;
    }

    for(int i = idx; i <= 9; i++){
        if(sum > n) break;

        temp.push_back(i);
        func(temp, ans, sum+i, i+1, k, n);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> temp;
    func(temp, ans, 0, 1, k, n);
    return ans;
}



int main(){
    vector<int> arr = {1, 2, 2};
    vector<vector<int>> ans = subset_sum_2(arr);
    for (int i = 0; i < ans.size(); i++){
        if (ans[i].empty()){                 
            cout << "{}"; 
        }
        else{
            for (int j = 0; j < ans[i].size(); j++){
                cout << ans[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}


/* 

[] (sum=0)
├── [1] (sum=1)
│   ├── [1, 2] (sum=3)
│   ├── [1, 3] (sum=4)
│   ├── [1, 4] (sum=5) → Valid
│   └── ...
├── [2] (sum=2)
│   ├── [2, 3] (sum=5) → Valid
│   ├── [2, 4] (sum=6) → Stop
│   └── ...
├── [3] (sum=3)
│   ├── [3, 4] → Stop
│   └── ...
└── ...


 */