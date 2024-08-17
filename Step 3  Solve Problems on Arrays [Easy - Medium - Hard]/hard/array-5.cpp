#include<bits/stdc++.h>
using namespace std;

// longest subarray with sum 0

// approach
// 1 - find all subarrays
// 2 - hashing(presum, idx)


void long_sub_0_sum(vector<int> arr, int n){
    // brute force 
    // idea : get all subarray and check for sum
    /* int max_len = 0;
    for(int i = 0; i < n; i++){
        int sum = arr[i];
        for(int j = i; j < n; j++){
            sum += arr[j];
            if(sum == 0){
                max_len = max(max_len, (j - i + 1));
            }
        }
    }
    cout<<"Max length : "<<max_len; */
    // TC : O(n^2)
    // SC : O(1)


    // optimal 
    // Idea : hashing(presum, idx)
    /* int maxi = 0;
    int sum  = 0;
    unordered_map<int, int> mpp;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum == 0){
            maxi = i + 1;
        }
        else if(mpp.find(sum) != mpp.end()){
            maxi = max(maxi, i - mpp[sum]);
        }
        else{
            mpp[sum] = i;   //TC : O (logn)
        }
    }
    cout<<"Max length : "<<maxi;
    // TC : O(n) one for loop and one can be for finding sum in map or inserting sum in map
    // SC : O(n)  if all prefx sum are diff */

}

int main(){
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = arr.size();
    long_sub_0_sum(arr, n);
    return 0;
}