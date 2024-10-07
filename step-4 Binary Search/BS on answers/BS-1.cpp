#include<bits/stdc++.h>
using namespace std;


// finding sqrt of given number using binary search

int sqrt_element(int val){
    // brute force
    // for(int i = 0; i < n; i++){
    //     if(i*i == val){
    //         return i;
    //     }
    // }
    // TC : O(n)


    // better
    int low = 1, high = val;
    long long ans = 1;
    while(low <= high){
        int mid = low + (high - low)/2;
        
        if(mid * mid <= val){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    // TC : O(log N)


    return ans;
}


int main(){
    cout<<sqrt_element(36);
    
}