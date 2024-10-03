#include<bits/stdc++.h>
using namespace std;


// single element is sorted array
// sigle element occurs once and all other occurs twice

// trick : (binary search)
// if mid is odd then its match is of left -> eleminate left half
// if mid is even then its match is of right -> eleminate right half

int single_sorted_array(vector<int> arr, int n){
    // brute force
    // if(n == 1){
    //     return arr[0];
    // }
    // for(int i = 0; i < n; i++){
    //     if(i == 0){
    //         if(arr[i] != arr[i+1]){
    //             return arr[0];
    //         }
    //     }
    //     else if(i == n-1){
    //         if(arr[i] != arr[i-1]){
    //             return arr[n-1];
    //         }
    //     }
    //     else{
    //         if(arr[i] != arr[i-1] && arr[i] != arr[i+1]){
    //             return arr[i];
    //         }
    //     }
    // }
    // TC : O(n)


    // better
    if(n == 1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];
    int low = 1, high = n-2;
    while(low <= high){
        int mid = low + (high - low) / 2;

        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]){
            return arr[mid];
        }

        // mid can be odd or even but equality factor decide the low or high value  
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1])){
            // this means pairs are perfect in left section we have check in right section
            low = mid + 1;
        }
        // this means the pairs are not correctly formed
        else{
            high = mid - 1;
        }
    }
    return -1;

    // TC : O(logn base2)
}


int main(){
    vector<int> arr = {10, 10, 14, 16, 16, 25, 25, 28, 28, 36, 36, 44, 44};
    int n = arr.size();
    int ans = single_sorted_array(arr, n);
    cout<<ans;
}