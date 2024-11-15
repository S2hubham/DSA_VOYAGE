#include <bits/stdc++.h>
using namespace std;


// Rotate String
bool func(string s, string goal){
    // brute
    /* if(s.length() != goal.length()) return false;
    int n = s.length();
    for(int i = 0; i < n; i++){
        char ch = s[0];
        s = s.substr(1, n);
        s += ch;
        if(s == goal){
            return true;
        }
    }
    return false; */

    // TC : O(n)
    // SC : O(1)


    //better
    if (s.length() != goal.length()) return false;
    string concatenated = s + s; // Concatenate the string with itself
    return concatenated.find(goal) != string::npos;  
    // npos check for position of start idx of required string if not found it will return false else true
    // string::npos is a constant defined in the std::string class, which represents an invalid position or an "out-of-bounds" index.
}

int main()
{
    
    string s = "abcde", t = "abced";
    if(func(s, t)){
        cout<<"True";
    }
    else{
        cout<<"Not true";
    }
    return 0;
}