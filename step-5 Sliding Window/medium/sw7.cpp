#include <bits/stdc++.h>
using namespace std;


// longest repeating character replacement
int func(string s, int k){
    // brute force
    /* int maxlen = 0, n = s.size();
    for(int i = 0; i < n; i++){
        vector<int> hash(26, 0);
        int maxf = 0;
        for(int j = i; j < n; j++){
            hash[s[j] - 'a']++;
            maxf = max(maxf, hash[s[j] - 'a']);
            int changes = (j - i + 1) - maxf;
            if(changes <= k){
                maxlen = max(maxlen , j - i + 1);
            }
            else{
                break;
            }
        }
    }
    return maxlen; */

    // TC : O(n^2)
    // SC : O(26)


    // better
    /* int maxlen = 0, l = 0, r = 0, n = s.size(), maxf = 0;
    unordered_map<char, int> mpp;
    while(r < n){
        mpp[s[r]]++;
        maxf = max(maxf, mpp[s[r]]);
        while(((r - l + 1) - maxf) > k){
            mpp[s[l]]--;

            maxf = 0;
            for(auto p : mpp) {    // TC : O(26)
                if (p.second > maxf) { 
                    maxf = p.second; 
                }
            }

            l++;
        }
        if(((r - l + 1) - maxf) <= k){
            maxlen = max(maxlen, (r - l + 1));
        }

        r++;
    }
    return maxlen; */

    // TC : O(n + n * 26)
    // SC : O(26)



    // optimal
    int maxlen = 0, l = 0, r = 0, n = s.size(), maxf = 0;
    unordered_map<char, int> mpp;
    while(r < n){
        mpp[s[r]]++;
        maxf = max(maxf, mpp[s[r]]);
        if(((r - l + 1) - maxf) > k){
            mpp[s[l]]--;
            // removed the maxf updation as it was unnecessary 
            l++;
        }
        if(((r - l + 1) - maxf) <= k){
            maxlen = max(maxlen, (r - l + 1));
        }

        r++;
    }
    return maxlen;

    // TC : O(n)
    // SC : O(26)
}



int main(){
    string s = "AABABBA";
    cout<<"Max length : "<<func(s, 2);
    return 0;
}