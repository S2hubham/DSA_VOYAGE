#include<bits/stdc++.h>
using namespace std;

// Minimum coins
vector<int> func(vector<int> arr, int value){
    int n = arr.size();
    vector<int> ans;
    for(int i = n-1; i >= 0; i--){
        while(value >= arr[i]){
            value -= arr[i];
            ans.push_back(arr[i]);
        }
    }
    return ans;
}


int main(){
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int value = 49;
    
    vector<int> ans = func(coins, value);

    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}