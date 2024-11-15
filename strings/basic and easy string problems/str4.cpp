#include <bits/stdc++.h>
using namespace std;


// Longest Common Prefix
string common(vector<string> s)
{
    string prefix = s[0];
    for(int i = 0; i < s.size(); i++){
        // matching idx
        int j = 0;
        while(j < prefix.length() && j < s[i].length() & prefix[j] == s[i][j]){
            j++;
        }

        // remove the non matching part
        prefix = prefix.substr(0, j);

        // check if there is any matching part or not
        if(prefix.length() == 0){
            break;
        }
    }
    return prefix;

    // TC : O(N * M)
    // N is the number of strings in the input vector.
    // M is the length of the shortest string in the input vector.
    
    // SC : O(1)
}


int main()
{
    vector<string> s = {"flower","flow","flight"};  
    string ans = common(s);
    for (int i = 0; i < ans.length(); i++)
    {
        cout << ans[i];
    }
}



/* 
ALGO : 

We start by considering the first string as the initial prefix.
For each subsequent string, we compare characters one by one to find the common prefix.
We reduce the prefix whenever a mismatch is encountered.
If the prefix becomes empty at any point, we stop further checks since no common prefix exists.


 */