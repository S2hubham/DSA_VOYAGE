#include <bits/stdc++.h>
using namespace std;


// Longest Substring with At Most K Distinct Characters 
int func(string s, int k){
    // brute force
    /* int n = s.length();
    int maxlen = 0;
    for(int i = 0; i < n; i++){
        unordered_set<char> st;
        for(int j = i; j < n; j++){
            st.insert(s[j]);
            if(st.size() > k)   break;
            maxlen = max(maxlen, j - i + 1);
        }
    }
    return maxlen; */

    // TC : O(n^2)
    // SC : O(3)

    // better 
    /* int l = 0, r = 0, maxlen = 0, n = s.size();
    unordered_map<char, int> mpp;
    while(r < n){
        mpp[s[r]]++;

        while(mpp.size() > k){
            mpp[s[l]] -= 1;
            if(mpp[s[l]] == 0)  mpp.erase(s[l]);
            l++; 
        }

        maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen; */

    // TC : O(2n)
    // SC : O(3)


    // optimal
    /* int maxlen = 0, l = 0, r = 0, n = s.size();
    unordered_map<char, int> mpp;
    while(r < n){
        mpp[s[r]]++;

        if(mpp.size() > k){
            mpp[s[l]] -= 1;
            if(mpp[s[l]] == 0)  mpp.erase(s[l]);
            l++;
        }

        if(mpp.size() <= k){
            maxlen = max(maxlen, r - l + 1);
        }

        r++;
    }
    return maxlen; */

    // TC : O(n)
    // SC : O(3)
}



int main(){
    string s = "aaabbccd";
    string s2 = "abcadcacacaca";
    cout<<"Maximum consecutive ones : "<<func(s, 2);
    return 0;
}