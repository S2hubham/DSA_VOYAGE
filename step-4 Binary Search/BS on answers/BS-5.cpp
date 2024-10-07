#include <bits/stdc++.h>
using namespace std;

// find smallest divisor given in a threshold
// summation of all ceil(quotients) should be less than equal to threshold

// 2 : ans is greater than threshold
// 1 : ans is equal than threshold
// 0 : ans is less than threshold

bool func(vector<int> arr, int threshold, int mid)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ans += ceil((double)arr[i] / (double)mid);
        if (ans > threshold)
            return 0;
    }
    return (ans <= threshold);
}

int minDivisor(vector<int> arr, int threshold)
{
    // edge case : if threshold is less than least summation
    int n = arr.size();
    if (n > threshold)
        return -1;

    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }

    int low = 1, high = maxi;
    int ans = high;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        bool val = func(arr, threshold, mid);
        if (func(arr, threshold, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;

    // TC : O(log(arr[max]) * n)
    // SC : O(1)
}

int main()
{
    vector<int> arr = {21212, 10101, 12121};
    cout << minDivisor(arr, 1000000);
}