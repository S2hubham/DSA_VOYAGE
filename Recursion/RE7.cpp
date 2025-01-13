#include<bits/stdc++.h>
using namespace std;


// count good numbers

const int MOD = 1e9 + 7; // explicitly given to return in this

long long func(long long base, long long exp, long long mod){
    long long result = 1;

    while(exp){
        if(exp % 2 == 1){  //if odd 
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }

    return result;
}

int count_good_no(long long n){
    // brute (recursive)
    /* if(n == 1){
        return 5;
    }
    long long val = count_good_no(n-1);
    if((n-1)%2 == 0){
        return (val * 5);
    }
    return (val * 4); */

    // TC : O(n)  
    // SC : O(n)



    // better
    int evencnt = (n+1) / 2;
    int oddcnt = n / 2;

    long long evenchoices = func(5, evencnt, MOD);
    long long oddchoices = func(4, oddcnt, MOD);

    return (evenchoices * oddchoices) % MOD;

    // TC : O(logn)        i.e. O(log(even_indices)+log(odd_indices)) = O(logn).
    // SC : O(1)
}


int main(){
    cout<<count_good_no(4);

    return 0;
}

