#include<bits/stdc++.h>
using namespace std;


// finding nth root of an integer

// return 1 if == m
// return 0 if < m
// return 2 if > m
int power(int mid, int n, int root){
    long long ans = 1;
    for(int i = 0; i < root; i++){
        ans = ans * mid;
        if(ans > n) return 2;
    }
    if(ans == n) return 1;
    return 0;
}

int sqrt_element(int n, int root){
    if (n == 0 || n == 1) return n; 

    int low = 1, high = n;
    while(low <= high){
        int mid = low + (high - low)/2;
        int val = power(mid, n, root);

        if(val == 1){
            return mid;
        }
        else if(val == 0){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    } 
    return -1;

    // TC : O(log M) * O(root)
}


int main(){
    cout<<sqrt_element(64, 2);
}