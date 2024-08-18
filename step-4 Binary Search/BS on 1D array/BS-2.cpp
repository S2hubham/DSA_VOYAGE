#include <bits/stdc++.h>
using namespace std;

// lower bound (smallest index with element greater than equal to given x)
int lowerbound(vector<int> arr, int n, int target)
{
    // brute force
    /* for(int i = 0; i < n; i++){
        if(arr[i] >= target){
            return i;
        }
    }
    return n; */

    // TC : O(n)
    // SC : O(1)

    // better(binary search)
    /* int ans = n;
    int low = 0; int high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] >= target){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans; */
    // int lb = lower_bound(arr.begin(), arr.end(), n)-arr.begin();
}

// upper bound(smallest index with element greater to given x)
int upperbound(vector<int> arr, int n, int target)
{
    // brute force
    /* for(int i = 0; i < n; i++){
        if(arr[i] > target){
            return i;
        }
    }
    return n; */

    // TC : O(n)
    // SC : O(1)

    // better(binary search)
    int ans = -1;
    int high = n - 1, low = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > target)
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
    // int ub = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
    // return ub;
}

// floor and ceil

vector<int> getFloorAndCeil(int x, vector<int> &arr)
{
    // code here
    int n = arr.size();
    int floor = -1, ceil = -1;
    int low = 0, high = n - 1;

    sort(arr.begin(), arr.end()); // Ensure the array is sorted

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            // If x is found in the array, both floor and ceil are x
            return {x, x};
        }
        else if (arr[mid] < x)
        {
            // Potential floor found
            floor = arr[mid];
            low = mid + 1;
        }
        else
        {
            // Potential ceil found
            ceil = arr[mid];
            high = mid - 1;
        }
    }

    return {floor, ceil};
}

int main()
{
    vector<int> arr = {1, 2, 3, 3, 7, 8, 9, 9, 9, 11};
    int n = arr.size();
    int x = 8;
    // int ans = lowerbound(arr, n, 4);
    // int ans = upperbound(arr, n, 22);
    // if (ans == -1)
    //     cout << n;
    // else
    //     cout << ans;
    vector<int> ans = getFloorAndCeil(x, arr);
    cout << "Floor: " << ans[0] << ", Ceil: " << ans[1] << endl;

    return 0;
}