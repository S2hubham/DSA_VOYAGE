#include <bits/stdc++.h>
using namespace std;


// longest substring without repeating chracters
int func(string s){
    // brute force 
    // form all the arrays and use hashing
    /* int maxlen = 0;
    int n = s.size();
    for(int i = 0; i < n; i++){
        vector<int> mpp(256, 0);
        for(int j = i; j < n; j++){
            if(mpp[s[j]] == 1){
                break;
            }
            maxlen = max(maxlen, j-i+1);
            mpp[s[j]] = 1;
        }
    }
    return maxlen; */

    // TC : O(n^2)
    // SC : (256)


    // better
    /* int l = 0, r = 0;
    int n = s.size();
    unordered_map<char, int> mpp;
    int maxlen = 0;
    while(r < n){
        if(mpp.find(s[r]) != mpp.end() && l <= mpp[s[r]]){
            l = mpp[s[r]] + 1;
        }
        maxlen = max(maxlen, r-l+1);
        mpp[s[r]] = r;
        r++;
    }
    return maxlen; */

    // TC : O(n)
    // SC : O(256)
}



int main(){
    string s = "cadbzabcd";
    string s1 = "abcdef";

    cout<<"Maximum substring : "<<func(s);

    return 0;
}