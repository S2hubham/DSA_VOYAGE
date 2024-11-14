#include <bits/stdc++.h>
using namespace std;


// Largest Odd Number in String
string largestOddNumber(string s)
{
    string ans = "";
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if ((s[i] - '0') % 2 != 0)
        {
            ans = s.substr(0, i + 1);
            return ans;
        }
    }
    return ans;
}


int main()
{
    string s = "4206";
    string ans = largestOddNumber(s);
    for (int i = 0; i < ans.length(); i++)
    {
        cout << ans[i];
    }
}