#include <bits/stdc++.h>
using namespace std;

// remove outermost paranthesis
string removeOuterParentheses(string str)
{
    string x;
    int cnt = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            cnt++;
            if (cnt > 1)
            {
                x += str[i];
            }
        }
        else
        {
            cnt--;
            if (cnt > 0)
            {
                x += str[i];
            }
        }
    }
    return x;
}

int main()
{
    string s = "(()())(())(()(()))";
    string ans = removeOuterParentheses(s);
    for (int i = 0; i < ans.length(); i++)
    {
        cout << ans[i];
    }
}

// I/P : (()())(())     O/P : ()()()
// I/P : (()())(())(()(()))     O/P : ()()()()(())
// I/P : ()()    O/P : nothing



// ALGO
/*  Algorithm to Remove Outermost Parentheses:

1. Initialize a result string `x` and a counter `cnt` to track the depth of parentheses.
2. Traverse each character of the input string `str`:
   - When encountering `(`, increment `cnt`. If `cnt > 1`, append `(` to `x` (this skips the outermost `(`).
   - When encountering `)`, decrement `cnt`. If `cnt > 0`, append `)` to `x` (this skips the outermost `)`).
3. Return the result string `x` which contains the inner parentheses after removing the outermost ones. */