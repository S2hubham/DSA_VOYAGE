#include<bits/stdc++.h>
using namespace std;


// Subsequence problems

void sub_seq(int i, int n, vector<int> &arr, vector<int> &ans){
    if(i == n){
        if(ans.size() == 0){
            cout<<"{}";
            return;
        }
        for(int i = 0; i < ans.size(); i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }
    // pick / take condition where this element is taken is seq
    ans.emplace_back(arr[i]);
    sub_seq(i+1, n, arr, ans);

    ans.pop_back();
    // not pick/not take condition where this element is not taken in seq
    sub_seq(i+1, n, arr, ans);

    // TC : O(2^n)
    // SC : O(n)
}


int main(){
    vector<int> arr = {1, 2, 3};
    vector<int> ans = {};
    sub_seq(0, arr.size(), arr, ans);

    return 0;
}


/*


                                          sub_seq(0, {})
                                   /                               \
                                  /                                 \
                 Include 1 --> sub_seq(1, {1})                             sub_seq(1, {})
                              /              \                            /                  \
                             /                \                          /                    \
        Include 2 --> sub_seq(2, {1, 2})       sub_seq(2, {1})           sub_seq(2, {2})             sub_seq(2, {})
                         /           \                 /       \               /     \                 /      \
                        /             \               /         \             /       \               /        \
Include 3 --> sub_seq(3, {1, 2, 3})    sub_seq(3, {1, 2})     sub_seq(3, {1, 3})     sub_seq(3, {1})
Exclude 3 --> sub_seq(3, {2, 3})       sub_seq(3, {2})        sub_seq(3, {3})        sub_seq(3, {})


*/


/* 

                       {}
                     /    \
                  {1}      {}
                /    \     /    \
            {1,2}   {1}  {2}     {}
           /   \   /   \  /  \   /  \
     {1,2,3} {1,2} {1,3} {1} {2,3} {2} {3} {}



*/