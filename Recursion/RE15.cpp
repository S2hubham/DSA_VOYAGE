#include <bits/stdc++.h>
using namespace std;

// subset sum 1

// brute force
void func(vector<int> arr, vector<int> &temp, vector<int> &ans, int i, int n){
    // base case
    if(i == n){
        int sum = 0;
        for(int i = 0; i < temp.size(); i++){
            sum += temp[i];
        }
        ans.push_back(sum);  // o(2^n)
        return;
    }
    // pick
    temp.push_back(arr[i]);
    func(arr, temp, ans, i+1, n);
    temp.pop_back();
    // non pick
    func(arr, temp, ans, i+1, n);
} 


vector<int> subset_sum(vector<int> arr){
    vector<int> ans;
    vector<int> temp;
    func(arr, temp, ans, 0, arr.size());
    sort(ans.begin(), ans.end());      
    return ans;

    // TC : O(O(2^n ) (recursive calls) +O(n*2^n ) (summation) +O(2^n log2^n) (sorting)
    //    : O(2^n log 2^n)   as sorting is required alse it will ne n*2^n

    // SC : O(n) (call stack) +O(n) (temp) +O(2^n) (ans) 
    //    : O(2^n) 
} 



// better force
/* void func(vector<int> arr, vector<int> &ans, int sum, int i, int n){
    // base case
    if(i == n){
        ans.push_back(sum);  // o(2^n)
        return;
    }
    // pick
    func(arr, ans, sum + arr[i], i+1, n);
    // non pick
    func(arr, ans, sum, i+1, n);
} 


vector<int> subset_sum(vector<int> arr){
    vector<int> ans;
    func(arr, ans, 0, 0, arr.size());
    sort(ans.begin(), ans.end());      // o(2^n log 2^n)  due to size of ans
    return ans;

    // Tc : O(2^n + 2^n log 2^n)     calls + sorting
    // SC : O(2^n)
} */



int main()
{
    vector<int> arr = {3, 1, 2};
    vector<int> ans = subset_sum(arr);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}



// recursion tree
/* 

 */