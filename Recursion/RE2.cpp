#include<bits/stdc++.h>
using namespace std;


// sum of first n numbers

// 1)functional way (function returns answer here)
int sum_f(int n){
    if(n == 1){
        return n;
    }
    return (n + sum_f(n-1));
}

// 2)Parameterized way (function prints the answer by using parameters)
void sum_p(int i, int sum){
    if(i < 1){
        cout<<sum;
        return;
    }
    sum_p(i-1, sum+i);
}


// factorial of n
int factorial_f(int n){
    if(n == 2){
        return n;
    }
    return n * factorial_f(n-1);
}

void factorial_p(int i, int mul){
    if(i < 2){
        cout<<mul;
        return;
    }
    factorial_p(i-1, mul*i);
}


int main(){
    // cout<<sum_f(3);
    // sum_p(3, 0);
    // cout<<factorial_f(5);
    factorial_p(5, 1);

    return 0;
}