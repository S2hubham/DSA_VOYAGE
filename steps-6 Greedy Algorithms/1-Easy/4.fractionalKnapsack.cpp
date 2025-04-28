#include<bits/stdc++.h>
using namespace std;

// Fractional Knapsack Problem
bool cmp(vector<int> &a, vector<int> &b){
    double x = (double)a[0] / a[1];
    double y = (double)b[0] / b[1];
    return x > y;
}

double func(vector<vector<int>> arr, int weight){
    sort(arr.begin(), arr.end(), cmp);
    
    double total = 0, i = 0, n = arr.size();
    while(weight && i < n){
        if(weight < arr[i][1]){
            double fract = (double)(arr[i][0] * weight / arr[i][1]);
            total += fract;
            break;
        }
        total += arr[i][0];
        weight -= arr[i][1];
        i++;
    }
    return total;

    // TC : O(nlogn + n)
    // SC : O(1)
}


int main(){
    vector<vector<int>> arr = {  
        {100, 20},
        {60, 10},
        {100, 50},
        {200, 50}
    };
    int weight = 90;   // 380

    vector<vector<int>> arr1 = {
        {60, 10},   
        {100, 20},  
        {120, 30}   
    };
    int weight1 = 50;  // 240
    
    cout<<"Total value is : "<<func(arr1, weight1);
    return 0;
}