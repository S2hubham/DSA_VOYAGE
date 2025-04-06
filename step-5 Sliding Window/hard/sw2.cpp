#include <bits/stdc++.h>
using namespace std;


// subarrays with k diff integers

int helper(vector<int>arr, int k){
    int cnt = 0, l = 0, r = 0, n = arr.size();
    unordered_map<int, int> mpp;
    while(r < n){
        if(k <= 0)   return 0;
        mpp[arr[r]]++;
        // reduce window to make it valid one
        while(mpp.size() > k){
            mpp[arr[l]]--;
            if(mpp[arr[l]] == 0)    mpp.erase(arr[l]);
            l++;
        }
        cnt += r - l + 1;
        r++;
    }
    return cnt;
}

int func(vector<int> arr, int k){
    // brute
    /* int n = arr.size(), cnt = 0;
    for(int i = 0; i < n; i++){
        unordered_set<int> st;
        for(int j = i; j < n; j++){
            st.insert(arr[j]);
            if(st.size() > k)   break;
            if(st.size() == k)  cnt++;
        }
    }
    return cnt; */

    // TC : O(n^2)
    // SC : O(k+1)


    // better
    int x = helper(arr, k);
    int y = helper(arr, k-1);
    return x - y;

    // TC : O(2 * 2n)
    // SC : O(2 * k)
}


int main(){
    vector<int> arr = {1, 2, 1, 3, 4};  // 3   
    vector<int> arr1 = {1, 2, 1, 2, 3};   // 7
    vector<int> arr2 = {2, 1, 1, 1, 3, 4, 3, 2};  // 9
    cout<<"No. of subarrays : "<<func(arr2, 3);
    return 0;
}