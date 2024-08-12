#include <bits/stdc++.h>
using namespace std;

// Reverse pairs
// arr[i] > 2 * arr[j] 


void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;   // SC : O(n)
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

}


int countPairs(vector<int>& arr, int low, int mid, int high){
    int count = 0;
    int right = mid+1;
    for(int i = low; i <= mid; i++){  //TC : O(n1)  low -> mid
        while(right <= high && (long long)arr[i] > 2*(long long)arr[right]){ //TC : O(n2) mid+1 -> high
            right++;
        }
        count += right - (mid+1);
    }
    return count;
    // TC : O(n1 + n2)  this is equivalent of (n) from merge 
}


int mergesort(vector<int>& arr, int low, int high) {
    if (low >= high) {
        return 0;
    }

    int mid = (low + high) / 2;
    int count = 0;
    count += mergesort(arr, low, mid);
    count += mergesort(arr, mid + 1, high);
    count += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);

    return count;
}

void rev_pairs(vector<int> arr, int n){
    // brute force
    /* int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > 2*arr[j]){
                count++;
            }
        }
    }
    cout<<count; */
    // TC : O(n^2)
    // SC : O(1)


    // better
    int count = 0; 
    count += mergesort(arr, 0, n-1);
    cout<<count;
    // TC : O(2n logn) 
    // SC : O(n)
}


int main()
{
    vector<int> arr1 = {40, 25, 19, 12, 9, 6, 2};
    int n1 = arr1.size();
    
    rev_pairs(arr1, n1);
    return 0;
}