#include <bits/stdc++.h>
using namespace std;

// merge two sorted arrays without using extra space

void swapGreater(vector<int> &arr1, vector<int> &arr2, int left, int right)
{
    if (arr1[left] > arr2[right])
    {
        swap(arr1[left], arr2[right]);
    }
}

void merge_two_sorted(vector<int> &arr1, vector<int> &arr2)
{
    /* int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> ans;
    int i = 0, j = 0;

    while(i < n1 && j < n2){
        if(arr1[i] <= arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        }
        else{
            ans.push_back(arr2[j]);
            j++;
        }
    }

    while(i < n1){
        ans.push_back(arr1[i]);
        i++;
    }

    while(j < n2){
        ans.push_back(arr2[j]);
        j++;
    }

    for(int i = 0; i < n1 + n2; i++){
        if(i < n1){
            arr1[i] = ans[i];
        }
        else{
            arr2[i - n1] = ans[i];
        }
    } */
    // TC : O(n+m) + O(n+m)
    // SC : O(n+m)

    // optimal - 1
    /* int n1 = arr1.size();
    int n2 = arr2.size();
    int i = n1 - 1;
    int j = 0;
    while(i >= 0 && j < n2){   //TC : O(n1, n2)
        if(arr1[i] > arr2[j]){
            swap(arr1[i], arr2[j]);
            i--;
            j++;
        }
        else{
            break;
        }
    }
    sort(arr1.begin(), arr1.end());  //TC : O(n1 logm)
    sort(arr2.begin(), arr2.end());  //TC : O(n2 logm) */
    // TC : O(n1, n2) + O(n1 logm) + O(n2 logm)
    // SC : O(1)

    // optimal - 2
    // idea : gap method
    int n1 = arr1.size();
    int n2 = arr2.size();
    int len = n1 + n2;
    int gap = (len / 2) + (len % 2);

    while (gap > 0) // TC : O(log(len) base2)
    {
        int left = 0;
        int right = left + gap;

        while (right < len) // TC : O(len)
        {
            // left poimter is in left array and right pointer is in right array
            if (left < n1 && right >= n1)
            {
                swapGreater(arr1, arr2, left, right - n1);
            }
            // both pointers are in right array
            else if (left >= n1)
            {
                swapGreater(arr2, arr2, left - n1, right - n1);
            }
            // both pointers are in left array
            else
            {
                swapGreater(arr1, arr1, left, right);
            }
            left++;
            right++;
        }

        if (gap == 1)
        {
            break;
        }

        gap = (gap / 2) + (gap % 2);
    }
    // TC : O(len log(len) base2)
    // SC : O(1)
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 0, 0, 0};
    vector<int> arr2 = {2, 5, 6};
    merge_two_sorted(arr1, arr2);
    cout << "arr1: ";
    for (int i : arr1)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "arr2: ";
    for (int i : arr2)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

// -------------------------
// leetcode que
/* You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1.
To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged,
and the last n elements are set to 0 and should be ignored. nums2 has a length of n. */

class Solution
{
private:
    void swapGreater(vector<int> &a, vector<int> &b, int left, int right)
    {
        if (a[left] > b[right])
        {
            swap(a[left], b[right]);
        }
    }

// here m and n are both same
public:
    void merge(vector<int> &a, int n, vector<int> &b, int m)
    {
        int len = n + m;
        int gap = (len / 2) + (len % 2);
        while (gap > 0)
        {
            int left = 0;
            int right = left + gap;
            while (right < len)
            {
                if (left < n && right >= n)
                {
                    swapGreater(a, b, left, right - n);
                }
                else if (left >= n)
                {
                    swapGreater(b, b, left - n, right - n);
                }
                else
                {
                    swapGreater(a, a, left, right);
                }
                left++;
                right++;
            }
            if (gap == 1)
                break;
            gap = (gap / 2) + (gap % 2);
        }

        // This was the whole que about
        int j = 0;
        for (int i = n; i < len; i++)
        {
            a[i] = b[j++];
        }
    }
};