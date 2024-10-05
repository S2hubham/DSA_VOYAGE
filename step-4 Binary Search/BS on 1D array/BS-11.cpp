#include<bits/stdc++.h>
using namespace std;


// finding nth root of an integer
int power(int mid, int root){
    for(int i = 0; i < root; i++){
        
    }
}

int sqrt_element(int n, int root){
    int low = 1, high = n;
    while(low <= high){
        int mid = low + (high - low)/2;
        int val = power(mid, root);

        if(val == n){
            return mid;
        }
        else if(val > n){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    } 
    return -1;
}


int main(){
    cout<<sqrt_element(16, 4);
    
}