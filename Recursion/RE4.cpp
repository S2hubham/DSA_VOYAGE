#include<bits/stdc++.h>
using namespace std;


// Multiple recursion calls

// Fibonacci Number
int fib(int n){
    if(n <= 1){
        return n;
    }
    int last = fib(n - 1);
    int slast = fib(n - 2);
    return (last + slast);

    // TC : O(2^n)
    // SC : O(n)
}


int main(){
    cout<<fib(5);

    return 0;
}