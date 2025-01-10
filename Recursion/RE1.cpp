#include<bits/stdc++.h>
using namespace std;


// print name n times
void print_name(int n){
    if(n == 0){
        return;
    }
    cout<<"Shubham\n";
    print_name(n-1);
}


// print 1 to n
void print_1_to_n(int i, int n){
    if(i > n) return;
    cout<<i<<endl;
    print_1_to_n(i+1, n);
}


// print n to 1
void print_n_to_1(int i, int n){
    if(i < 1){
        return;
    }
    cout<<i<<endl;
    print_n_to_1(i-1, n);
}


// print 1 to n  (backtracking i.e. not using plus operator)
void print_1_to_n_bt(int i, int n){
    if(i < 1) return;
    print_1_to_n_bt(i-1, 10);
    cout<<i<<endl;
}


// print n to 1  (backtracking i.e. not using minus operator)
void print_n_to_1_bt(int i, int n){
    if(i > n) return;
    print_n_to_1_bt(i+1, 10);
    cout<<i<<endl;
}


int main(){
    print_name(5);
    print_1_to_n(1, 10);
    print_n_to_1(5, 5);
    print_1_to_n_bt(10, 10);
    print_n_to_1_bt(1, 10);
    return 0;
}