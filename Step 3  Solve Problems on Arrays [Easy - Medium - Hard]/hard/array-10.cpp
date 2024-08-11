#include <bits/stdc++.h>
using namespace std;


// maximum product subarray
void max_pro_subarray(vector<int> arr, int n){
    // bettter
    /* int max_prod = INT_MIN;
    for(int i = 0; i < n; i++){
        int prod = 1;
        for(int j = i; j < n; j++){
            prod *= arr[j];
            max_prod = max(max_prod, prod);
        }
    }
    cout<<max_prod; */

    // TC : O(n^2)
    // SC : O(1)

    // optimal
    int maxi = INT_MIN;
    int pre = 1;
    int suff = 1;
    for(int i = 0; i < n; i++){
        if(pre == 0){
            pre = 1;
        } 
        if(suff == 0){
            suff = 1;
        } 

        pre = pre * arr[i];
        suff = suff * arr[n - i - 1];

        maxi = max(maxi, max(pre, suff));
    }

    cout<<maxi;
    // TC : O(n)
    // SC : O(1)

}




int main(){
    vector<int> arr = {3, 2, -2, 4};
    int n = arr.size();
    max_pro_subarray(arr, n);
}