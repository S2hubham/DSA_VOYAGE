#include <bits/stdc++.h>
using namespace std;


// Isomorphic Strings

/* Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
*/

bool isIsomorphic(string s, string t)
{
    // edge case
    if (s.length() != t.length())
        return false;

    unordered_map<char, char> mapST;
    unordered_map<char, char> mapTS;

    for (int i = 0; i < s.length(); i++)
    {
        char c1 = s[i];
        char c2 = t[i];

        if ((mapST.count(c1) && mapST[c1] != c2) || (mapTS.count(c2) && mapTS[c2] != c1))
        {
            return false;
        }

        mapST[c1] = c2;
        mapTS[c2] = c1;
    }

    return true;

    // TC : O(n)
    // SC : O(n)
    // In the worst case, for strings of length n, if all characters are unique, the size of the hash maps can be O(n)
}


int main()
{
    
    string s = "egg", t = "add";
    if(isIsomorphic(s, t)){
        cout<<"isomorphic";
    }
    else{
        cout<<"Not isomorphic";
    }
    return 0;
}



/* 
ALGO : 
Check Lengths:

If the lengths of the two strings s and t are not equal, they cannot be isomorphic. Return false.
Use Two Hash Maps:

Create two hash maps (or arrays) to track character mappings:
mapST to map characters from s to t.
mapTS to map characters from t to s.
Traverse through both strings simultaneously:
For each character c1 in s and c2 in t:
If c1 is already mapped in mapST and it does not map to c2, return false.
If c2 is already mapped in mapTS and it does not map to c1, return false.
Otherwise, create mappings:
mapST[c1] = c2
mapTS[c2] = c1
Return true:

If the loop completes without finding inconsistencies, the strings are isomorphic.

 */