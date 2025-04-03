#include <bits/stdc++.h>
using namespace std;


// fruit into baskets 
int func(vector<int> arr){
    // brute force
    /* int maxlen = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        unordered_set<int> st;
        for(int j = i; j < n; j++){
            st.insert(arr[j]);
            if(st.size() > 2)   break;
            maxlen = max(maxlen, j-i+1);
        }
    }
    return maxlen; */

    // TC : O(n^2)
    // SC : O(3)

    // better 
    int maxlen = 0, l = 0, r = 0, n = arr.size();
    unordered_map<int, int> mpp;
    while(r < n){
        mpp[arr[r]]++;

        while(mpp.size() > 2){
            mpp[arr[l]] -= 1;
            if(mpp[arr[l]] == 0){
                mpp.erase(arr[l]);
            }
            l++;
        }

        maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen; 

    // TC : O(2n)
    // SC : O(3)


    // optimal
    /* int maxlen = 0, l = 0, r = 0, n = arr.size();
    unordered_map<int, int> mpp;
    while(r < n){
        mpp[arr[r]]++;

        if(mpp.size() > 2){
            mpp[arr[l]] -= 1;
            if(mpp[arr[l]] == 0){
                mpp.erase(arr[l]);
            }
            l++;
        }

        if(mpp.size() <= 2){
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    return maxlen; */

    // TC : O(n)
    // SC : O(3)
}



int main(){
    vector<int> arr = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    vector<int> arr1 = {2, 1, 2};
    cout<<"Maximum consecutive ones : "<<func(arr1);
    return 0;
}