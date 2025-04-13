#include <bits/stdc++.h>
using namespace std;


// minimum window substring
string func(string s, string t){
    // brute
    /* int minlen = INT_MAX, sIndex = -1;
    for(int i = 0; i < s.size(); i++){
        int cnt = 0;
        unordered_map<char, int> mpp;
        for(int k = 0; k < t.size(); k++){
            mpp[t[k]]++;
        }
        for(int j = i; j < s.size(); j++){
            if(mpp[s[j]] > 0){
                cnt++;
            }
            mpp[s[j]]--;
            if(cnt == t.size()){
                if(j-i+1 < minlen){
                    minlen = j-i+1;
                    sIndex = i;
                }
                break;
            }
        }
    }
    string ans = s.substr(sIndex, minlen);
    return ans; */

    // TC : O(n^2)
    // SC : O(256)


    // better
    int l = 0, r = 0, minlen = INT_MAX, cnt = 0, sIndex = -1;
    int n = s.size(), m = t.size();
    unordered_map<char, int> mpp;
    for(int i = 0; i < m; i++){
        mpp[t[i]]++;
    }
    while(r < n){
        if(mpp[s[r]] > 0)   cnt++;
        mpp[s[r]]--;

        while(cnt == m){
            if(minlen > r-l+1){
                minlen = r-l+1;
                sIndex = l;
            }
            mpp[s[l]]++;
            if(mpp[s[l]] > 0)   cnt--;
            l++;
        }
        r++;
    }

    return (sIndex == -1 ? "" : s.substr(sIndex, minlen));

    // TC : O(2n)
    // SC : O(256)
}


int main(){
    string s = "ddaaabbca";
    string t = "abc";
    cout<<"Min len substring is : "<<func(s, t);
    return 0;
}