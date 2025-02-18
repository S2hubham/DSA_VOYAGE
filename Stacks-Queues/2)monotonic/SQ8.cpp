#include <bits/stdc++.h>
using namespace std;


// sum of subarray ranges
void sum_subarray_ranges(vector<int> arr){
    // brute force
    int total = 0;
    for(int i = 0; i < arr.size(); i++){
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int j = i; j < arr.size(); j++){
            mini = min(arr[j], mini);
            maxi = max(arr[j], maxi);
            int range = maxi - mini;
            total += range;
        }
    }
    cout<<"Total : "<<total;

    // TC : O(n^2)
    // SC : O(1)

    
}

int main(){
    vector<int> arr = {1, 4, 3, 2};
    sum_subarray_ranges(arr);
    return 0;
}