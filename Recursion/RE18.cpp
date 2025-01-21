#include <bits/stdc++.h>
using namespace std;

// permutations

// brute force  (uses hashing intuition hence require extra space)
/* void func(vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans, int mpp[]){
    // base case
    if(temp.size() == arr.size()){
        ans.push_back(temp);
        return;
    }

    for(int i = 0; i < arr.size(); i++){
        if(!mpp[i]){
            temp.push_back(arr[i]);
            mpp[i] = 1;
            func(arr, temp, ans, mpp);
            temp.pop_back();
            mpp[i] = 0;
        }  
    }
}[]

vector<vector<int>> permutations(vector<int> arr) {
    vector<vector<int>> ans;
    vector<int> temp;
    int mpp[arr.size()];
    for(int i = 0; i < arr.size(); i++){
        mpp[i] = 0;
    }
    func(arr, temp, ans, mpp);
    return ans;

    // TC : O(n * n!)   we are forming n! permutations ans for ach permutation we are storing the temp in ans 
    // SC : O(n * n!)   for storing the results
} */



// better  (hashing is not considered but still the TC and SC remains unchanged)
void func(vector<int> &arr, vector<vector<int>> &ans, int idx){
    // base case
    if(idx == arr.size()){
        ans.push_back(arr);
        return;
    }

    for(int i = idx; i < arr.size(); i++){
        swap(arr[idx], arr[i]);
        func(arr, ans, idx+1);
        swap(arr[idx], arr[i]);
    }
}

vector<vector<int>> permutations(vector<int> arr) {
    vector<vector<int>> ans;
    vector<int> temp;
    func(arr, ans, 0);
    return ans;

    // TC : O(n * n!)
    // SC : O(n * n!)
} 


int main(){
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans = permutations(arr);
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