#include <bits/stdc++.h>
using namespace std;

// count inversion
// arr[i] > arr[i+1]

// approach
// 1 - two loops for iteration
// 2 - count varaible + merge sort

int merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;   // SC : O(n)
    int count = 0;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            count += mid - left + 1;
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

    return count;
}


int mergesort(vector<int>& arr, int low, int high) {
    if (low >= high) {
        return 0;
    }

    int mid = (low + high) / 2;
    int count = 0;
    count += mergesort(arr, low, mid);
    count += mergesort(arr, mid + 1, high);
    count += merge(arr, low, mid, high);

    return count;
}


void count_inverson(vector<int> &arr, int n){
    // brute force
    /* int count = 0;
    for(int i = 0; i < n; i++){
        int ele = arr[i];
        for(int j = i+1; j < n; j++){
            if(ele > arr[j]){
                count++;
            }
        }
    }
    cout<<count; */
    // TC : O(n^2)
    // SC : O(1)


    // better 
    // idea : merge sort + finding pairs (left > right) before sorting
    int count = 0;
    count = mergesort(arr, 0, n - 1);
    cout << "Optimized inversion count: " << count << endl;

    // TC : O(nlogn)
    // SC : O()
}



int main(){
    vector<int> arr = {5, 3, 2, 4, 1};
    int n = arr.size();
    count_inverson(arr, n);
}
