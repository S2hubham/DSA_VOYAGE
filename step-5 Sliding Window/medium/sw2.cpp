#include <bits/stdc++.h>
using namespace std;


// Maximum points u can obtain from n cards
int func(vector<int> arr, int k){
    // brute force
    /* int ans = 0;
    for(int i = k - 1; i >= 0; i--){
        int sizeL = i + 1;
        int sizeR = k - sizeL;
        int sum = 0;
        int j = 0, k = arr.size()-1;
        while(sizeL > 0 && j < arr.size()){
            sum += arr[j++];
            sizeL--;
        }
        while(sizeR > 0 && k >= 0){
            sum += arr[k--];
            sizeR--;
        }
        ans = max(ans, sum);
    }
    return ans; */

    // TC : O(k*k)  one for outer for loop one for calculating sum
    // SC : O(1)   


    // better in terms of wriring code and loops 
    /* int n = arr.size();
    int lsum = 0, rsum = 0, maxsum = 0; 
    for(int i = 0; i < k; i++){
        lsum += arr[i];
    }
    maxsum = lsum;

    int r = n-1;
    for(int i = k-1; i >= 0; i--){
        lsum -= arr[i];
        rsum += arr[r];
        r--;
        maxsum = max(maxsum , lsum+rsum);
    }

    return maxsum; */

    // TC : O(k + k) one for lsum then one for removing each ele from lsum
    // SC : O(1)
}



int main(){
    // vector<int> arr = {6, 2, 3, 4, 7, 2, 1, 7, 1};
    // int k = 4;
    vector<int> arr = {1, 100, 3, 50, 7, 6, 9, 2, 20};
    int k = 3;

    cout<<"Maximum points u can obtain from "<<k<<" cards : "<<func(arr, k);

    return 0;
}