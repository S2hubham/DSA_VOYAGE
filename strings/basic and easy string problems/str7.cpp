#include <bits/stdc++.h>
using namespace std;

bool anagram(string s, string t){
    /* if(s.length() != t.length()) return false;
    unordered_map<char, int> mapST;
    unordered_map<char, int> mapTS;
    for(int i = 0; i < s.length(); i++){
        char c1 = s[i], c2 = t[i];
        mapST[c1]++, mapTS[c2]++;
    }
    for (const auto& pair : mapST) {
        auto it = mapTS.find(pair.first);
        if (it == mapTS.end() || it->second != pair.second) {
            return false;
        }
    }
    return true; */

    // TC : O(n)
    // SC : O(n)


    // better (use only 1 map)
    if(s.length() != t.length()) return false;
    unordered_map<char, int> countChar;
    for(char c : s){
        countChar[c]++;
    }
    for (char c : t) {
        if(--countChar[c] < 0){
            return false;
        }
    }
    return true;

    // TC : O(n)
    // SC : O(1)

}

int main()
{
    string s = "cat";
    string t = "act";
    if(anagram(s, t)){
        cout<<"Anagram";
    }
    else{
        cout<<"Not Anagram";
    }
    return 0;
}


/* 
ALGO : 

Count characters in s: Populate charCount with the frequency of characters in s.
Decrement counts for t: For each character in t, decrement its count in charCount. If any count becomes negative, the strings are not anagrams.

 */