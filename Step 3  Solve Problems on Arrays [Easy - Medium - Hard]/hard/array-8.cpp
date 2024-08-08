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

    while (gap > 0)  //TC : O(log(len) base2)
    {
        int left = 0;
        int right = left + gap;

        while (right < len)   //TC : O(len)
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
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {0, 2, 6, 8, 9};
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