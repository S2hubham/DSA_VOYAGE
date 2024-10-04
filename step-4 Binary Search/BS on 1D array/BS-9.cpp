#include<bits/stdc++.h>
using namespace std;


// find peak element 
// arr[i-1] < arr[i] > arr[i+1]
// consider before and after of array is -infinity

int peak_element(vector<int> arr, int n){
    // brute
    // for(int i = 1; i < n-1; i++){
    //     if((i == 0 || arr[i] > arr[i-1]) && (i == n-1 || arr[i] > arr[i+1])){
    //         return arr[i];
    //     }
    // } 

    // TC : O(n)
    // SC : O(1)


    // better(for single peak)
    if(n == 1) return arr[0];
    if(arr[0] > arr[1]) return arr[0];
    if(arr[n-1] > arr[n-2]) return arr[n-1];
    int low = 1, high = n-2;
    while(low <= high){
        int mid = low + (high - low)/2;

        if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){
            return arr[mid];
        }
        else if(arr[mid-1] < arr[mid]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}


int main(){
    vector<int> arr = {1, 5, 1, 2, 1};
    int n = arr.size();
    cout<<peak_element(arr, n);
    // for(auto it : ans){
    //     cout<<it<<endl;
    // }
}



// edge case
// 1 5 1 2 1
// here we can eleminate any part so that we can get the peak