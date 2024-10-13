#include <bits/stdc++.h>
using namespace std;

// painter partition / split array largest sum

int allocate(vector<int> arr, int mid){
    int painters = 1, units = 0;
    for(int i = 0; i < arr.size(); i++){
        if((arr[i] + units) <= mid){
            units += arr[i];
        }
        else{
            painters += 1;
            units = arr[i];
        }
    }
    return painters;
}

int painter(vector<int> arr, int p)
{  
    int n = arr.size();
    if(p > n) return -1;
    int maxi = INT_MIN, sum = 0;
    for(int i = 0; i < n; i++){
        maxi = max(maxi, arr[i]);
        sum += arr[i];
    }
    int low = maxi, high = sum;
    while(low <= high){
        int mid = low + (high - low)/2;
        int val = allocate(arr, mid);
        if(val > p){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40}; 
    cout <<"Minimum no. of pages allocated is : "<< painter(arr, 2);
}
