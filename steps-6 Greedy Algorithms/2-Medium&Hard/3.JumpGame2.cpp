#include<bits/stdc++.h>
using namespace std;

// Jump Game 2
int jump_rec(vector<int> arr, int idx, int jumps){
    // base case
    if(idx >= arr.size()-1){
        return jumps;
    }

    int mini_jump = INT_MAX;
    for(int i = 1; i <= arr[idx]; i++){
        mini_jump = min(mini_jump, jump_rec(arr, idx+i, jumps+1));
    }

    return mini_jump;
}   

int func(vector<int> arr){
    // brute force
    /* int ans = jump_rec(arr, 0, 0);
    return (ans == INT_MAX) ? -1 : ans;  */

    // TC : O(n^n) exponential
    // SC : O(n)


    // better
    int jumps = 0, l = 0, r = 0;
    while(r < arr.size()-1){
        int farthest = 0;
        for(int i = l; i <= r; i++){
            farthest = max(farthest, i + arr[i]);
        }
        l = r++;
        r = farthest;
        jumps++;
    }
    return jumps;

    // TC : O(n)
    // SC : O(1)

}


int main(){
    vector<int> hops = {1, 2, 3, 1, 1, 0, 2, 5}; 
    int minJumps = func(hops);
    cout << "Minimum jumps to reach end: " << minJumps << endl;
    return 0;
}