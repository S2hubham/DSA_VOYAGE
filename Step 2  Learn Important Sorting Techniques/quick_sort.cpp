#include <bits/stdc++.h>
using namespace std;

int pivot(int arr[], int low, int high){
    int pivot_ele = arr[low];
    int i = low;
    int j = high;
    while(i < j){
        //this loop will find the element which is greater than pivot
        // <= due to all small and equal elements are placed placed on right
        while(arr[i] <= pivot_ele && i <= high-1){
            i++;
        }
        //this loop will find the element which is lesser than pivot
        // > bcoz all greater elements are placed on right
        while(arr[j] > pivot_ele && i >= low+1){
            j--;
        }
        //swaps only when they haven't crossed 
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);  //j is the last element of left index
    return j; 
}

void quick_sort(int arr[], int low, int high){
    if(low < high){
        int p = pivot(arr, low, high);
        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    quick_sort(arr, 0, n - 1);  // Corrected range

    // Print the sorted array
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}