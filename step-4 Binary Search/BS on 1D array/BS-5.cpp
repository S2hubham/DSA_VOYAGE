#include<bits/stdc++.h>
using namespace std;


// search in rotated sorted array(duplicates)
// edge case : arr[low] == arr[mid] == arr[high]

void search_rot_sorted_array2(vector<int> arr, int n, int target){
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low + high) / 2; 

        if(arr[mid] == target){
            cout<<"true";
            return;
        }

        // check for dupliactes
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low = low + 1;
            high = high - 1;
            continue;
        }

        // left portion is sorted
        if(arr[low] <= arr[mid]){
            if(arr[low] <= target && target <= arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        // right portion is sorted
        else{
            if(arr[mid] <= target && target <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    cout<<"false";

    // avg TC : O(logn base2)
    // worst TC : O(n/2)
}

int main(){
    vector<int> arr = {3, 3, 1, 3, 3, 3, 3};
    int n = arr.size();
    int x = 8;
    search_rot_sorted_array2(arr, n, 1);
}