#include <bits/stdc++.h>
using namespace std;


// count number of nice subarrays
int helper(vector<int> arr, int goal){
    int l = 0, r = 0, n = arr.size(), cnt = 0, sum = 0;
    while(r < n){
        sum += arr[r] % 2;
        while(sum > goal){
            sum -= arr[l] % 2;
            l++;
        }
        cnt += (r - l + 1);
        r++;
    }
    return cnt;
}

int func(vector<int> arr, int goal){
    int x = helper(arr, goal);
    int y = helper(arr, goal-1);
    return x-y;
}



int main(){
    vector<int> arr = {1, 5, 2, 1, 7};   // 2
    vector<int> arr1 = {2,2,2,1,2,2,1,2,2,2};  //16
    cout<<"No. of subarrays : "<<func(arr1, 2);
    return 0;
}