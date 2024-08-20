#include<bits/stdc++.h>
using namespace std;

// search in rotated sorted array
void search_rot_sorted_array(vector<int> arr, int n, int target){
    int low = 0, high = -1;
    while(low <= high){
        int mid = (low + high) / 2; 
        if(arr[mid] == target){
            cout<<"Found at index : "<<mid;
            return;
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
    cout<<"not found";

    // TC : O(logn base2)
    // SC : O(1)
}


int main(){
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = arr.size();
    int x = 8;
    search_rot_sorted_array(arr, n, 1);
}



/* 

algo

find mid
check if mid == target
find the sorted portion (left or right)
    check whether the target lies within the sorted portion before searching for target
        if yes shift the low or high accordingly
        if no shift the low or high accordingly


 */