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
}

int main()
{
    vector<int> arr1 = {1,2,3,0,0,0};
    int n1 = arr1.size();
    vector<int> arr2 = {2,5,6};
    int n2 = arr2.size();
    
    merge(arr1, n1, arr2, n2);
    cout << "arr1: ";
    for (int i : arr1)
    {
        cout << i << " ";
    }
    return 0;
}