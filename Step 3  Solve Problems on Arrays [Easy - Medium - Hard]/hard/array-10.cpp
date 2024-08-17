#include <bits/stdc++.h>
using namespace std;


// maximum product subarray

// approach
// 1 - find all sub-arrays 
// 2 - prefix sum and suffix sum

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

    // optimal - 1 (prefix and suffix)
    /* int maxi = INT_MIN;
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

    cout<<maxi; */
    // TC : O(n)
    // SC : O(1)


    // optimal - kadanes algo extended
    int maxProd = arr[0];
    int minProd = arr[0];
    int result = arr[0];
    for(int i = 1; i < n; i++){
        int temp = max({arr[i], maxProd*arr[i], minProd*arr[i]});
        minProd = min({arr[i], maxProd*arr[i], minProd*arr[i]});
        maxProd = temp;

        result = max(result, maxProd);
    }
    cout<<result;

    // TC : O(n)
    // SC : O(1)

}




int main(){
    vector<int> arr = {1,2,-3,4,5,0};
    int n = arr.size();
    max_pro_subarray(arr, n);
}