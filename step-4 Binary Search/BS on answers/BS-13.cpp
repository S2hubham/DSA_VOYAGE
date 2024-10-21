#include <bits/stdc++.h>
using namespace std;

// median of two sorted arrays

int k_element(vector<int> arr1, vector<int> arr2, int k)
{
    // brute force
    /* int n1 = arr1.size(), n2 = arr2.size();
    int i = 0, j = 0;
    int count = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            if (count == k)
                return arr1[i];
            count++;
            i++;
        }
        else
        {
            if (count == k)
                return arr2[j];
            count++;
            j++;
        }
    }
    while (i < n1)
    {
        if (count == k)
            return arr1[i];
        count++;
        i++;
    }
    while (j < n2)
    {
        if (count == k)
            return arr2[j];
        count++;
        j++;
    }
    return -1; */

    // TC : O(n1+n2)
    // SC : O(1)


    // better
    int n1 = arr1.size(), n2 = arr2.size();
    int n = n1 + n2;
    if(n1 > n2) k_element(arr2, arr1, k);
    int left = k;
    int low = max(0, k - n2), high = min(k, n1);
    while(low <= high){
        int mid1 = low + (high - low)/2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid1 - 1 >= 0) l1 = arr1[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = arr2[mid2 - 1];
        if(mid1 < n1) r1 = arr1[mid1];
        if(mid1 < n2) r2 = arr1[mid1];

        if(l1 <= r2 && l2 <= r1){
            return max(l1, l2);
        }
        else if(l1 > r2){
            high = mid1 - 1;
        }
        else{
            low = mid1 + 1;
        }
    }
    return -1;

    // TC : O(log(min(n1, n2)))
}

int main()
{
    vector<int> arr1 = {1, 3, 4, 7, 10, 12};
    vector<int> arr2 = {2, 3, 6, 15};
    cout << "Kth element is : " << k_element(arr1, arr2, 5);

}