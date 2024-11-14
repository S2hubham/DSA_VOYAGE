#include <bits/stdc++.h>
using namespace std;

// Reverse Words in a String
string reverseWords(string str)
{

    int start = 0, end = str.length() - 1;
    while (start <= end && str[start] == ' ')
        start++;
    while (end >= start && str[end] == ' ')
        end--;

    str = str.substr(start, end - start + 1);
    reverse(str.begin(), str.end());

    int n = str.length();
    int wordstart = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i == n || str[i] == ' ')
        {
            reverse(str.begin() + wordstart, str.begin() + i);
            wordstart = i + 1;
        }
    }

    string ans;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        char ch = str[i];
        if (ch != ' ')
        {
            ans += ch;
            flag = false;
        }
        else if (!flag)
        {
            ans += ch;
            flag = true;
        }
    }
    return ans;

    // T C: O(n)
    // SC : O(n)
}

int main()
{
    string s = "  Hello                     World  ";
    string ans = reverseWords(s);
    for (int i = 0; i < ans.length(); i++)
    {
        cout << ans[i];
    }
}

/*  Algorithm :

1. Trim Leading and Trailing Spaces:
   - Remove spaces from the beginning and end of the input string.

2. Reverse the Entire String:
   - Reverse all characters in the string.

3. Reverse Individual Words:
   - Traverse the string to identify words (delimited by spaces) and reverse each word in place.

4. Remove Extra Spaces:
   - Traverse the string again to remove multiple spaces, leaving only one space between words.

 Complexity:
- Time: \(O(n)\)
- Space: \(O(n)\) (due to the final output string) */
