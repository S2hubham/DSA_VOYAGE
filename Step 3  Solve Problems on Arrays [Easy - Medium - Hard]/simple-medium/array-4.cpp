#include <bits/stdc++.h>
using namespace std;

// longest subarray with sum k (positive elements)
void long_subarray(int arr[], int N, int K)
{
    //-----brute force
    // divide the array into all possible subarrays and then calculate the sum and check for maximum length
    // TC ~ O(n2)
    // SC : O(1)

    //----optimal for arrays with only positives and negatives
    /*int sum = 0;
    int max_len = 0;
    map<int, int> temp;

    // Iterate through the array
    for(int i = 0; i < N; i++){
        // Add the current element to the cumulative sum
        sum += arr[i];

        // Check if the cumulative sum equals K
        if(sum == K){
            max_len = max(max_len, i + 1);
        }

        // Calculate the remainder (sum - K)
        int rem = sum - K;

        // Check if the remainder has been seen before
        if(temp.find(rem) != temp.end()){
            // Calculate the length of the subarray
            int len = i - temp[rem];
            max_len = max(max_len, len);
        }

        // Store the first occurrence of the cumulative sum
        if(temp.find(sum) == temp.end()){
            temp[sum] = i;
        }
    }

    // Return the maximum length of subarray with sum K
    cout<<"Length of max suarray with sum " << K <<" is " << max_len;*/

    // TC : O(n logn)
    // SC : O(n)

    

    // optimal for arrays with only positives and zeros
    /*int sum = 0;
    int right = 0;
    int left = 0;
    int max_len = 0;

    while (right < N)
    {
        sum += arr[right];

        // If sum exceeds K, subtract the left elements till sum becomes <= K
        while (sum > K && left <= right)
        {
            sum -= arr[left];
            left++;
        }

        // If sum == K, calculate the max length
        if (sum == K)
        {
            max_len = max(max_len, right - left + 1);
        }

        right++;
    }

    cout << "Length of max subarray with sum " << K << " is " << max_len;*/

    // TC : O(2N) inner loop runs for n times for all iterations of outer loop
    // SC : O(1)
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long_subarray(arr, n, 12);
}

// explanation for long_subarray
// Consider A = [10, 5, 2, 7, 1, 9], N = 6, and K = 15:

// Initialize sum = 0, max_len = 0, and temp as an empty map.
// Iterate through each element in A:
// For i = 0: sum = 10, temp becomes {10: 0}
// For i = 1: sum = 15, since sum == K, update max_len = 2.
// For i = 2: sum = 17, rem = 2, temp becomes {10: 0, 15: 1, 17: 2}
// For i = 3: sum = 24, rem = 9, temp becomes {10: 0, 15: 1, 17: 2, 24: 3}
// For i = 4: sum = 25, rem = 10, since rem is in temp, calculate length 4 - 0 = 4, update max_len = 4.
// For i = 5: sum = 34, rem = 19, temp becomes {10: 0, 15: 1, 17: 2, 24: 3, 25: 4, 34: 5}
// The function returns max_len = 4.
// This function efficiently finds the length of the longest subarray with the sum equal to K using a hash map to store cumulative sums and their indices.