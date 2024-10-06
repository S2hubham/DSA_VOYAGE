#include<bits/stdc++.h>
using namespace std;


// Koko eating banana
// return the min integer k(bananas/hr) such that koko can eat all bananas within h hours

int maxi(vector<int> arr){
    int max_el = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > max_el){
            max_el = arr[i];
        }
    }
    return max_el;
}

long long func(vector<int> arr, int k){
    int totalhrs = 0;
    for(int i = 0; i < arr.size(); i++){
        totalhrs += ceil((double)arr[i] / (double)k);
    }
    return totalhrs;
}

int koko(vector<int> arr, int allowed_time){
    int low = 1, high = maxi(arr);
    int ans = high;
    while(low <= high){
        int mid = low + (high - low)/2;

        long long totalhrs = func(arr, mid);

        if(totalhrs <= allowed_time){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
    // n is the number of piles (size of arr),
    // max(arr) is the maximum number of bananas in any pile.
    // Thus, the time complexity is O(n log(max(arr))).
}


int main(){
    vector<int> arr = {3, 6, 7, 11};
    cout<<koko(arr, 8);
    // for(auto it : ans){
    //     cout<<it<<endl;
    // }
}
