#include<bits/stdc++.h>
using namespace std;

// Jump Game 1
bool func(vector<int> arr){
    int maxIdx = 0, n = arr.size();
    for(int i = 0; i < n; i++){
        if(i > maxIdx)  return false;
        int nextHop = i + arr[i];
        maxIdx = max(maxIdx, nextHop);
    }
    return true;

    // TC : O(n)
    // SC : O(1)
}


int main(){
    vector<int> hops = {1, 2, 3, 1, 1, 0, 2, 5};  // false
    vector<int> hops1 = {1, 2, 4, 1, 1, 0, 2, 5};  // true
    if(func(hops1)){
        cout<<"Can reach the end.";
    }
    else{
        cout<<"Not possible to reach end.";
    }
    return 0;
}