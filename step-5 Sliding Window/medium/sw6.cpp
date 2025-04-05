#include <bits/stdc++.h>
using namespace std;


// number of substrings containig all three characters a, b, c
int func(string s){
    // brute force
    /* int n = s.size(), cnt = 0;
    for(int i = 0; i <= n-3; i++){
        unordered_set<char> st;
        for(int j = i; j < n; j++){
            st.insert(s[j]);          // O(1)
            if(st.size() == 3){
                cnt += n - j;
                break;
            }
        }
    }
    return cnt; */

    // TC : O(n^2)
    // SC : O(1)


    // better
    /* int l = 0, r = 0, n = s.size(), cnt = 0;
    unordered_map<char, int> mpp;
    while(r < n){
        mpp[s[r]]++;

        while(mpp.size() >= 3){
            cnt += n - r;
            mpp[s[l]]--;
            if(mpp[s[l]] == 0){
                mpp.erase(s[l]);
            }
            l++;
        }

        r++;
    }
    return cnt; */

    // TC : O(2n)
    // SC : O(3)


    // optimal 
    vector<int> chars = {-1, -1, -1};
    int cnt = 0, n = s.size();
    for(int i = 0; i < n; i++){
        chars[s[i] - 'a'] = i;
        if(chars[0] != -1 && chars[1] != -1 && chars[2] != -1){
            int window = min(chars[0], min(chars[1], chars[2]));
            cnt += window + 1;
        }
    }
    return cnt;

    // TC : O(n)
    // SC : O(1)
}



int main(){
    string s = "bbacba";   // 9
    string s1 = "abcabc";  // 10
    string s2 = "abc";     // 1
    string s3 = "aaacb";   // 3 
    cout<<"Maximum number of substring containing all three characters : \n"<<func(s);
    return 0;
}




/* 

basic intuition for optimal

We want to count how many substrings end at each position that contain at least one 'a', one 'b', and one 'c'.
So, as we go through the string:
We remember the last positions where we saw:
'a' → chars[0]
'b' → chars[1]
'c' → chars[2]

At any point, if we've seen all three characters at least once, then we can form some valid substrings that end at the current character.
===The earliest of the last seen 'a', 'b', and 'c' tells us the furthest back we can start the substring and still include all three.===
So, the number of such substrings is just:
👉 window + 1
(because we can start from index 0 up to window)

📦 Example:
Let’s take s = "abc":
At i = 0: we see 'a' → not enough info.
At i = 1: we see 'b' → still missing 'c'.
At i = 2: we see 'c' → now we’ve seen 'a', 'b', and 'c'!

Last seen positions:
'a' → 0
'b' → 1
'c' → 2

The earliest of these is 0 → So we can start from index 0, and form 1 valid substring:
"abc" → ends at i = 2, starts at index 0
So: cnt += 0 + 1 = 1


*/