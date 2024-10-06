#include<bits/stdc++.h>
using namespace std;


// minimum no. of days to make M bouquets
// condition : bouquet will be formed by using three adjacent(unique) flower

bool possible(vector<int> arr, int mid, int b, int f){
    int cnt = 0, nob = 0; 
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] <= mid){
            cnt++;
        }
        else{
            nob += cnt / f;
            cnt = 0;
        }
    }
    nob += cnt / f;
    return nob >= b;
}

// b : no. of bouquets
// f : no. of flowers
int flowers(vector<int> arr, int b, int f){
    // edge case
    long long val = (long long) b * (long long) f;
    if(val > arr.size()) return -1;

    int mini = INT_MAX, maxi = INT_MIN;
	for(int i = 0; i < arr.size(); i++){
		mini = min(mini, arr[i]);
		maxi = max(maxi, arr[i]);
	}

    int low = mini, high = maxi;
    int ans = high; //by default highest no will satisfy the condition hence

    while(low <= high){
        int mid = low + (high - low)/2;

        if(possible(arr, mid, b, f)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
    // Time Complexity: O(log(max(arr[])-min(arr[])+1) * N), 
    // where {max(arr[]) -> maximum element of the array, min(arr[]) -> minimum element of the array, N = size of the array}.
}


int main(){
    vector<int> arr = {1, 2, 1, 2, 7, 2, 2, 3, 1};
    cout<<"Min no. of days required are : "<<flowers(arr, 2, 3);
    
}


// Constraints :
// 1 <= n <= 10^5
// 1 <= arr[i] <= 10^9
// 1 <= k <= n
// 1 <= m <= 10^6

// data types 
// int can handle upto 10^9
// for their multiplication use long long