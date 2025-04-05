#include <bits/stdc++.h>
using namespace std;


// Binary subarray with sum / count subarrays with sum k
int helper(vector<int> arr, int goal){
    int l = 0, r = 0, n = arr.size(), sum = 0, cnt = 0;
    while(r < n){ 
        // edge case 
        if(goal < 0)    return 0;

        sum += arr[r];
        while(sum > goal){
            sum -= arr[l];
            l++;
        }
        cnt += r-l+1;
        r++;
    }
    return cnt;
}

int func(vector<int> arr, int goal){
    // brute
    /* int n = arr.size(), presum = 0, cnt = 0;
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    for(int i = 0; i < n; i++){
        presum += arr[i];
        int rem = presum - goal;
        cnt += mpp[rem];
        mpp[presum]++;
    }
    return cnt; */

    // TC : O(n)
    // SC : O(n)



    // better
    int x = helper(arr, goal);
    int y = helper(arr, goal-1);
    return (x-y);

    // TC : O(2* 2n)
    // SC : O(1)
}



int main(){
    vector<int> arr = {1, 0, 1, 0, 1};   // 4
    vector<int> arr1 = {1, 0, 0, 1, 1, 0};  // 7
    cout<<"No. of subarrays : "<<func(arr, 2);
    return 0;
}