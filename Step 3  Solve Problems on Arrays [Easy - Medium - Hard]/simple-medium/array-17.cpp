#include<bits/stdc++.h>
using namespace std;

// number of subarray sum equals K
void no_subarrray_with_sum_k(int arr[], int n, int k){
    // brute
    int count = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            if(sum == k){
                count++;
            }
        }
    }
    cout<<count;


    // optimal
    /* int count = 0;
    int prefixSum = 0;
    unordered_map<int, int> hash;
    hash[0] = 1;
    for(int i = 0; i < n; i++){
        prefixSum += arr[i];
        int rem = prefixSum - k;
        count += hash[rem];
        hash[prefixSum] += 1;
    }

    cout<<count; */
    // TC : O(n x logn)
    // SC : O(n)
}


int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    no_subarrray_with_sum_k(arr, n, 6);
    return 0;
}