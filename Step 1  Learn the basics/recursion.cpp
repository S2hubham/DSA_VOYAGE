#include <bits/stdc++.h>
using namespace std;

int i = 1;
void name(int n)
{
    if (i > n)
    {
        return;
    }
    cout << "Shubham\n";
    i++;
    name(n);

    // TC : O(n)
    // SC : O(n)
}

// 1 to n
void digit(int n)
{
    if (i > n)
    {
        return;
    }
    cout << i << endl;
    i++;
    digit(n);

    // TC : O(n)
    // SC : O(n)
}

// backtrack(1 to n)
void b_digit(int i, int n)
{
    if (i < 0)
    {
        return;
    }
    b_digit(i - 1, n);
    cout << i << endl;
}

// n to 1
void rdigit(int n)
{
    if (n < 1)
    {
        return;
    }
    cout << n << endl;
    n--;
    digit(n);
}

// backtrack(n to 1)
void b_rdigit(int j, int n)
{
    if (j > n + 1)
    {
        return;
    }
    b_rdigit(j + 1, n);
    cout << n - (j - 1) << endl; // Using only the plus sign to achieve the decrement
}

//--------RE:3
// paramter
int add(int i, int sum)
{
    if (i < 1)
    {
        cout << sum << endl;
        return sum;
    }
    add(i - 1, sum + i);
}

// functional
int addf(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return (n + addf(n - 1));
}

// factorial
int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return (n * factorial(n - 1));

    // TC: O(n)
    // SC: O(n)
}

// factorial less than given number N
vector<long long> factorialNumbers(long long N)
{
    vector<long long> result;
    long long factorial = 1;
    int i = 1;

    while (factorial <= N)
    {
        result.push_back(factorial);
        i++;
        factorial *= i;
    }

    return result;
}

// RE:4------------
void rev_array(int i, int arr[], int n)
{
    if (i >= n / 2)
        return;
    swap(arr[i], arr[n - i - 1]);
    rev_array(i + 1, arr, n);
}

// palindorme array(functional)
bool palindrome(int i, string arr[], int n)
{
    if (i >= n / 2)
    {
        return true;
    }
    else if (arr[i] == arr[n - i - 1])
    {
        return palindrome(i + 1, arr, n);
    }
    else
    {
        return false;
    }
}

// or
bool isPalindrome(string s)
{
    string clean;
    for (int i = 0; i < s.size(); i++)
    {
        if (isalnum(s[i]))
        {
            clean += tolower(s[i]);
        }
    }
    int left = 0;
    int right = clean.size() - 1;
    while (left < right)
    {
        if (clean[left] != clean[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// RE:5----------
//(fibonacci number: 0 1 1 2 3 5 8 13 ....)(last term+prelast term)
int fibonacci(int n)
{
    int last, slast;
    if (n <= 1)
    {
        return n;
    }
    // return (fibonacci(n-1) + fibonacci(n-2));
    // first this will happen
    last = fibonacci(n - 1);
    // then this will happen
    slast = fibonacci(n - 2);
    return (last + slast);

    // From this tree, you can see that the number of calls grows exponentially, leading to the 𝑂(2𝑛) time complexity.
    // space complexity is 𝑂(𝑛),considering the depth of the recursion tree.
}

int main()
{
    // int x, y;
    // cin >> x;

    // cin >> y;
    // name(x);

    // digit(x);
    // reverse using only +ve sign(backtrack)
    // b_digit(x);

    // rdigit(x);
    // reverse using only -ve sign(backtrack)
    // b_rdigit(x, y);

    // RE:3
    // add(x, 0);
    // cout<<addf(x);
    // cout << factorial(x);

    // RE:4
    // int n;
    // cin >> n;
    // string arr[n];
    // for (int j = 0; j < n; j++)
    // {
    //     cin >> arr[i];
    // }
    // for (int j = 0; j < n; j++)
    // {
    //     cout << arr[i] << " ";
    // }
    // // rev_array(0, arr, n);

    // bool isPalindrome = palindrome(0, arr, n);
    // cout << boolalpha;
    // cout << "Result (true or false): " << isPalindrome << endl;

    int a;
    cin >> a;
    cout << fibonacci(a);

    return 0;
}
