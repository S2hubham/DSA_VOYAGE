#include <bits/stdc++.h>
using namespace std;

void no_digit(int n)
{
    int digits1 = (int)(log10(n) + 1);
    int digits2 = 0;
    int last_digit;
    while (n > 0)
    {
        last_digit = n % 10;
        cout << last_digit << " ";
        digits2++;
        n = n / 10;
    }
    cout << endl
         << "Number of digits " << digits2 << " " << digits1;

    // TC : O(log10(n));

    // NOTE : as the numbers are getting divided by 10 for every iteration the digits are getting reduced by one while n>0
    // so whenever the there is divisions for iteration the TC comes in log (if getting divided by 10 log10(n), if by 5 log5(n),...)
}

void reverse(int n)
{
    int reverse = 0; // always assign it to zero
    int l_digit = 0;
    while (n > 0)
    {
        l_digit = n % 10;
        reverse = (reverse * 10) + l_digit;
        n = n / 10;
    }
    cout << "reverse : " << reverse;

    // TC : O(log10(n));
}

// palindrome means number same to its reversed number
void palindrome(int n)
{
    int orignal = n;
    int reverse = 0;
    int l_digit = 0;
    while (n > 0)
    {
        l_digit = n % 10;
        reverse = (reverse * 10) + l_digit;
        n = n / 10;
    }
    if (orignal == reverse)
    {
        cout << "yes " << orignal << " is a palindrome";
    }
    else
    {
        cout << "Not a palindrome";
    }

    // TC : O(log10(n));
}

// armstrong number: 371 (condtion:3^3 + 7^3 + 1^3 == 371), 1634(1^4 + 6^4 + 3^4 + 4^4 == 1634)
void armstrong(int n)
{
    int orignal = n;
    int sum = 0;
    int l_digit;
    // calculate digits
    int digits = (int)(log10(n) + 1);
    // calculate sum
    while (n > 0)
    {
        l_digit = n % 10;
        sum = sum + pow(l_digit, digits); // pow(number, raise to)
        n = n / 10;
    }
    // check
    if (orignal == sum)
    {
        cout << "yes " << orignal << " is a armstrong";
    }
    else
    {
        cout << "Not a armstrong";
    }
}

void divisors(int n)
{
    // define vector to store unsorted divisors
    vector<int> v;
    // loop will go till square root of number
    for (int i = 1; i * i <= n; i++) //(TC:O(sqrt(n)))
    {
        // to get numbers before sqrt
        if (n % i == 0)
        {
            v.push_back(i); // TC:O(1)
            // to get numbers after sqrt except repetated number
            if ((n / i) != i)
            {
                v.push_back(n / i);
            }
        }
    }
    // sorting the divisors (TC:O(sqrt(n)logn))
    sort(v.begin(), v.end());
    // for each loop without *
    for (auto it : v)
    {
        cout << it << " "; // TC:O(sqrt(n))
    }

    // final TC : O(sqrt(n) log(sqrt(n)))

    // exp : After collecting the divisors, the vector v is sorted. Sorting v takes O(m log m) time, where m is the number of divisors. Since m can be at most 2 * sqrt(n), this sorting operation takes O(sqrt(n) log(sqrt(n))) time.
    //(note: if i dont wanted the divisors to be sorted the TC is O(sqrt(n)))
}

void prime(int n)
{
    int count = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            count++;
            if ((n / i) != i)
            {
                count++;
            }
        }
    }
    if (count == 2)
    {
        cout << n << " is a prime number";
    }
    else
    {
        cout << n << " is not a prime number";
    }

    // TC: O(sqrt(n))
}

void gcd_hcf(int a, int b)
{
    int gcd;
    for (int i = min(a, b); i > 0; i--)
    {
        if ((a % i == 0) && (b % i == 0))
        {
            gcd = i;
            break;
        }
    }
    cout << gcd;

    // TC : O(min(a, b))
}

// gcd(a, b) = gcd(a-b, b) or gcd(a % b, b) (if a > b)
//             gcd(b-a, a) or gcd(b % a, a) (if b > a)
void euclidean(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    if (a == 0)
    {
        cout << "gcd is : " << b;
    }
    else
    {
        cout << "gcd is : " << a;
    }

    // TC : O(log(min(a, b)) / log(phi))
    // phi due to division by a or b
}

int main()
{
    int x, y;
    cin >> x;
    cin >> y;
    // no_digit(x);
    // reverse(x);
    // palindrome(x);
    // armstrong(x);
    // divisors(x);
    // prime(x);
    // gcd_hcf(x, y);
    // euclidean(x, y);
}