#include <bits/stdc++.h>
using namespace std;

// string to integer
int s_i(string s)
{
    int i = 0;
    int ans = 0;
    bool isSigned = false;

    while (i < s.length() && s[i] == ' ')
    {
        i++;
    }

    if (i == s.length())
    { // if string is empty
        return ans;
    }

    if (s[i] == '-')
    {
        isSigned = true;
        i++;
    }
    else if (s[i] == '+')
    {
        i++;
    }

    while (i < s.length() && isdigit(s[i]))
    {
        if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && (s[i] - '0') > INT_MAX % 10))
        {
            return (isSigned) ? INT_MIN : INT_MAX;
        }

        ans = ans * 10 + (s[i] - '0');
        i++;
    }

    return (isSigned) ? -ans : ans;

    // TC : O(n)
    // SC : O(1)
}

int main()
{
    cout << s_i("word and 987");

    return 0;
}


/* 

if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && (s[i] - '0') > INT_MAX % 10)) {
    return isSigned ? INT_MIN : INT_MAX;
}

First part: ans > INT_MAX / 10
This checks if ans is large enough that multiplying it by 10 will exceed the maximum limit of a 32-bit signed integer. If ans is already greater than INT_MAX / 10, multiplying it by 10 would overflow the integer range.

Example: If ans = 214748364 and you try to multiply it by 10, the result would be 2147483640, which is greater than INT_MAX (2147483647). This would overflow.
Second part: (ans == INT_MAX / 10 && (s[i] - '0') > INT_MAX % 10)
This part handles the edge case when ans is exactly INT_MAX / 10 (i.e., 214748364). In this case, multiplying ans by 10 won't overflow by itself, but adding the next digit might. This check ensures that if the last digit exceeds INT_MAX % 10 (which is 7 for a 32-bit signed integer), the number would overflow.

Example: If ans = 214748364 (which is INT_MAX / 10), and the next digit s[i] is 8 (i.e., s[i] - '0' = 8), multiplying ans by 10 and adding 8 would result in 2147483648, which exceeds INT_MAX and causes an overflow.
Final Handling:
If either of these conditions is true, it means an overflow will occur if the conversion proceeds further, so the function returns INT_MAX or INT_MIN depending on the sign (isSigned).

If the number is positive (i.e., isSigned == false), return INT_MAX.
If the number is negative (i.e., isSigned == true), return INT_MIN.

 */