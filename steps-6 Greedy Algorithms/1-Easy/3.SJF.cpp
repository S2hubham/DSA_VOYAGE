#include<bits/stdc++.h>
using namespace std;

// Shortest Job First
long func(vector<int> arr){
    sort(arr.begin(), arr.end());
    int wt = 0, avg_wt = 0;
    for(int i = 0 ; i < arr.size(); i++){
        avg_wt += wt;
        wt += arr[i];
    }
    return (avg_wt / arr.size());

    // TC : O(n + nlogn)
    // SC : O(1)
}


int main(){
    vector<int> processes = {4, 3, 7, 1, 2};
    cout<<"Average waiting time is : "<<func(processes);
    return 0;
}