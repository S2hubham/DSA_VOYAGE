#include<bits/stdc++.h>
using namespace std;


// Minimum in rotated sorted array

void search_rot_sorted_array2(vector<int> arr, int n){
    int low = 0;
    int high = n-1;
    int val = INT_MAX;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] <= arr[high]){
            val = min(val, arr[mid]);
            high = mid - 1;
        }
        else{
            val = min(val, arr[mid]);
            low = mid + 1;
        }
    }

    cout<<val;

    // avg TC : O(logn base2)
    // worst TC : O(n/2)
}

int main(){
    vector<int> arr = {3, 3, 1, 0, 3, 3, 3};
    int n = arr.size();
    search_rot_sorted_array2(arr, n);
}