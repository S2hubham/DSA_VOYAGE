#include<bits/stdc++.h>
using namespace std;

// binary search to find x

int rec(int arr[], int low, int high, int x) {
    if (low > high) {
        return -1; // Element not found
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == x) {
        return mid;
    } 
    else if (arr[mid] < x) {
        return rec(arr, mid + 1, high, x);
    } 
    else {
        return rec(arr, low, mid - 1, x);
    }
}


void BS(int arr[], int n, int x){
    /* int low = 0;
    int high = n-1;
    while(low <= high){
        // either use long long or below approach for very large array
        int mid = (low + (high - low))/2;
        if(arr[mid] == x){
            cout<<"found";
            return;
        } 
        else if(arr[mid] < x){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    cout<<"not found"; */

    int ans = rec(arr, 0, n - 1, x);
    if (ans != -1) {
        cout << "found at index " << ans;
    } else {
        cout << "not found";
    }

    // TC : O(logn base2)
    // SC : O(1)
}





int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    BS(arr, n, 6);
    return 0;
}