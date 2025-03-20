#include <bits/stdc++.h>
using namespace std;


// sliding window patterns

// 1. constant window  (keep sliding the constant window)
int pattern_one(vector<int> arr, int k){
    int l = 0, r = k-1;
    int sum = 0;
    for(int i = 0; i < k; i++){
        sum += arr[i];
    }

    int ans = sum;
    while(r < arr.size()-1){
        sum -= arr[l];
        l++, r++;
        sum += arr[r];

        ans = max(ans, sum);
    }

    return ans;
}


// 2. longest subarray/substring with condition
int pattern_two(vector<int> arr, int k){
    // brute force
    /* int n = arr.size();
    int maxLength = 0;

    // Generate all subarrays
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j]; 
            if (sum <= k) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }

    return maxLength; */

    // TC : O(n^2)
    // SC : O(1)



    // better 
    /* int l = 0, r = 0, maxlen = 0, sum = 0;
    while(r < arr.size()){
        sum += arr[r];
        while (sum > k)
        {
            sum -= arr[l];
            l += 1;
        }
        
        if(sum <= k){
            maxlen = max(maxlen, r-l+1);
        }

        r += 1;
    }
    return maxlen; */

    // TC : O(2n) one for expanding one for shrinking
    // SC : O(1)



    // optimal
    int l = 0, r = 0, maxlen = 0, sum = 0;
    while(r < arr.size()){
        sum += arr[r];
        if(sum > k)
        {
            sum -= arr[l];
            l += 1;
        }
        
        if(sum <= k){
            maxlen = max(maxlen, r-l+1);
        }

        r += 1;
    }
    return maxlen;
}




int main(){
    // vector<int> arr1 = {-1, 2, 3, 3, 4, 5, -1};
    // cout<<"Max sum is : "<<pattern_one(arr1, 4);

    // vector<int> arr2 = {3, 1, 2, 1, 1, 1, 4, 5, 6};
    // cout<<"Max len of subarray is : "<<pattern_two(arr2, 5);

    vector<int> arr3 = {3, 1, 2, 1, 1, 1, 4, 5, 6};
    cout<<"Max len of subarray is : "<<pattern_two(arr3, 5);
}