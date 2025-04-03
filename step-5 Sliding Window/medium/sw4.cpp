#include <bits/stdc++.h>
using namespace std;


// max consecutive ones 
int func(vector<int> arr, int k){
    // brute force
    /* int n = arr.size();
    int maxlen = 0;
    for(int i = 0; i < n; i++){
        int zero_cnt = 0;
        for(int j = i; j < n; j++){
            if(arr[j] == 0) zero_cnt++;
            if(zero_cnt > k)    break;
            int len = j - i + 1;
            maxlen = max(maxlen, len);
        }
    }
    return maxlen; */

    // TC : O(n^2)
    // SC : O(1)


    // better 
    /* int n = arr.size();
    int l = 0, r = 0, maxlen = 0, cnt = 0;
    while(r < n){
        if(arr[r] == 0){
            cnt++;
            if(cnt > k){
                while(l < n && arr[l] == 1){
                    l++;
                }
                l++;
                cnt--;
            }
        }
        maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen; */

    // TC : O(2n)  one for r and another for l
    // SC : O(1)


    // optimal
    int n = arr.size();
    int l = 0, r = 0, maxlen = 0, cnt = 0;
    while(r < n){
        if(arr[r] == 0) cnt++;
        if(cnt > k){
            if(arr[l] == 0) cnt--;
            l++;
        }
        if(cnt <= k){
            maxlen = max(maxlen, r-l+1);
        }
        r++;
    }
    return maxlen;

    // TC : O(n)
    // SC : O(1)
}



int main(){
    vector<int> arr = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    vector<int> arr1 = {1, 1, 0, 0, 0, 1, 1, 1, 0};
    vector<int> arr2 = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k = 3;

    cout<<"Maximum consecutive ones : "<<func(arr2, k);
    return 0;
}