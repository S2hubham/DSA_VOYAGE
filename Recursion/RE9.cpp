#include<bits/stdc++.h>
using namespace std;


// pow(x, n)
double myPow(double x, int n) {
    // brute force
    /* double ans = 1;
    for(int i = 0; i < n; i++){
        ans *= x;
    }
    return ans; */

    // TC : O(n)
    // SC : O(1)



    // recursive
    /* if(n == 1){  
        return x;
    }
    x *= myPow(x, n-1);
    return x; */

    // TC : O(n)
    // SC : O(1)



    // better
    // handle negative power n (egde case)
    if(n < 0){
        x = 1 / x;
        n = -n;
    }

    double ans = 1;
    while(n){
        if(n % 2 == 1){
            ans *= x;
        }
        x *= x;
        n /= 2;
    }
    return ans;

    // TC : O(logn)
    // SC : O(1)
}


int main(){
    double ans = myPow(2, -10);
    cout<<ans;

    return 0;
}

