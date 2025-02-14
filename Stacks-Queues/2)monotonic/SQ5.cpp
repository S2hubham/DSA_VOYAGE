#include <bits/stdc++.h>
using namespace std;
#define SIZE 10


// Trapping rain water
int trapping_water(vector<int> arr){
    // brute force
    /* int n = arr.size();
    // step 1) form prefix max and suffix max
    int prefixMax[n];
    prefixMax[0] = arr[0];
    for(int i = 1; i < n; i++){
        prefixMax[i] = max(prefixMax[i-1], arr[i]);
    }
    int suffixMax[n];
    suffixMax[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--){
        suffixMax[i] = max(suffixMax[i+1], arr[i]);
    }

    // step 2) find the water trapped
    // int leftMax = -1;   better than keeping prefixMax array
    int total = 0;
    for(int i = 0; i < n; i++){
        int leftMax = prefixMax[i];
        // leftMax = max(leftMax, arr[i]);
        int rightMax = suffixMax[i];
        if(arr[i] < leftMax && arr[i] < rightMax){
            total += min(leftMax, rightMax) - arr[i];
        }
    }
    return total; */

    // TC : O(3n)
    // SC : O(2n)  or O(n) if not used prefixMax



    // better
    int n = arr.size(); 
    int total = 0;
    int leftmax = 0, rightmax = 0;
    int left = 0, right = n-1;
    while(left < right){
        if(arr[left] <= arr[right]){
            if(leftmax > arr[left]){
                total += leftmax - arr[left];
            }
            else{
                leftmax = arr[left];
            }
            left += 1;
        }
        else{
            if(rightmax > arr[right]){
                total += rightmax - arr[right];
            }
            else{
                rightmax = arr[right];
            }
            right -= 1;
        }
    }
    return total;

    // TC : O(n)
    // SC : O(1)
}

int main(){
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout<<trapping_water(arr);;
    return 0;
} 