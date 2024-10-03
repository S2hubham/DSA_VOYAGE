#include<bits/stdc++.h>
using namespace std;


// find out how many times array has been rotated

void rot_sorted_array(vector<int> arr, int n){
    int low = 0, high = n - 1;
    int index = -1;
    int ans = INT_MAX;
    while(low <= high){
        int mid = low + (high - low)/2;

        // check for dupliactes iff they are present in the array
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low++;
            high--;
            continue;
        }

        if(arr[low] <= arr[high]){
            if(arr[low] < ans){
                index = low;
                ans = arr[low];
            }
            break;
        }


        if(arr[low] <= arr[mid]){
            if(arr[low] < ans){
                index = low;
                ans = arr[low];
            }
            low = mid  + 1;
        }
        else{
            if(arr[mid] < ans){
                index = mid;
                ans = arr[mid];
            }
            high = mid - 1;
        }
    }
    cout<<"Times the rotated array is : "<<index;
}


int main(){
    vector<int> arr = {41, 48, 8, 10, 20, 30, 34, 35};
    int n = arr.size();
    rot_sorted_array(arr, n);
}