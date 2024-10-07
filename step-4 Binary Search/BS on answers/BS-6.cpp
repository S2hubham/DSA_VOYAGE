#include <bits/stdc++.h>
using namespace std;

// Capacity to Ship Packages within D Days

int findDays(vector<int> arr, int capacity)
{
    int days = 1, load = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (load + arr[i] > capacity)
        {
            days = days + 1;
            load = arr[i];
        }
        else
        {
            load += arr[i];
        }
    }
    return days;
}

int minDivisor(vector<int> arr, int days)
{
    int n = arr.size();
    int maxi = INT_MIN;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
        sum += arr[i];
    }

    // if low becomes less than the max value in array then the values greater than the low will never get loaded on the ship
    int low = maxi, high = sum;
    int ans = high;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int val = findDays(arr, mid);
        if (val <= days)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;

    // TC : O(log(arr[max]) * n)
    // SC : O(1)
}

int main()
{
    vector<int> arr = {5, 4, 5, 2, 3, 4, 5, 6}; // 34
    cout << minDivisor(arr, 5);
}