#include<bits/stdc++.h>
using namespace std;


// reverse an array

void swap(int &l, int &r){
    int temp = l;
    l = r;
    r = temp;
}

// 1) using left and right pointers
void reverse_lr(vector<int> &arr, int l, int r){
    if(l >= r) return;
    swap(arr[l], arr[r]);
    reverse_lr(arr, l+1, r-1);
}


// 2) using single pointer
void reverse_1(vector<int> &arr, int i, int n){
    if(i >= (n/2)) return;
    swap(arr[i], arr[n-i-1]);
    reverse_1(arr, i+1, n);
}




// check string is palindrome or not
bool palind(string s, int i, int n){
    if(i >= (n/2)){
        return true;
    }
    return ((s[i] == s[n-i-1]) ? palind(s, i+1, n) : false);
}


int main(){
    // vector<int> arr = {1, 2, 3, 4, 5};
    // reverse_lr(arr, 0, arr.size()-1);
    // reverse_1(arr, 0, arr.size());
    // for(int i = 0; i < arr.size(); i++){
    //     cout<<arr[i]<<" ";
    // }


    string s = "racecar";
    int n = s.size();
    if(palind(s, 0, n)){
        cout<<"Is a palindrome";
    }
    else{
        cout<<"Is not a palindrome";
    }

    return 0;
}