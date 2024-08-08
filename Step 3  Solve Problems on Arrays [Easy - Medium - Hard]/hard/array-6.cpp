#include<bits/stdc++.h>
using namespace std;

// count number of subarray with XOR as K
void XOR_K(vector<int> arr, int n, int k){
    // better
    // idea : xor
    /* int count = 0;
    for(int i = 0; i < n; i++){
        int xor1 = 0; 
        for(int j = i; j < n; j++){
            xor1 = xor1 ^ arr[j]; 
            if(xor1 == 6){  
                count++;  
            }
        }
    }
    cout<<count; */
    // TC : O(n^2)
    // SC : O(1)


    // optimal
    /* int xr = 0;
    int count = 0;
    unordered_map<int, int> mpp;
    mpp[xr]++;  //{0, 1}
    for(int i = 0; i < n; i++){
        xr = xr ^ arr[i];
        int x = xr ^ k;
        count += mpp[x];
        mpp[xr]++;
    }
    cout<<count; */
    // TC : O(n logn)
    // SC : O(n)
}

int main(){
    vector<int> arr = {4, 2, 2, 6, 4};
    int n = arr.size();
    XOR_K(arr, n, 6);
    return 0;
}

/* 
// optimal
-calculate xor
-find x = xr ^ k
-increment count
-store front xr in map 

 */