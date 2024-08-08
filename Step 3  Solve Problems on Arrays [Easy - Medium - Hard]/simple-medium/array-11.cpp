#include <bits/stdc++.h>
using namespace std;

// next permutation
void next_permutation(int arr[], int n)
{
    //----- brute force
    // generate all sorted permutations
    // linearly search for the element
    // the next index is our required answer(if doesn't exist then first element is ans)

    // TC : O(n! x n)
    // SC : O(n!)

    //-----better
    // STL library function next_permutation(A.begin(), A.end())
    // return A;

    //-----optimal
    int index = -1;
    // find the break point
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            index = i;
            break;
        }
    }

    // edge case if no breakpoint exist
    if (index == -1)
    {
        reverse(arr, arr + n);
    }
    else
    {
        // swap the index with next maximum present in right part
        for (int i = n - 1; i > index; i--)
        {
            if (arr[i] > arr[index])
            {
                swap(arr[i], arr[index]);
                break;
            }
        }

        // reverse the remaining array
        reverse(arr + (index + 1), arr + n);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // TC : O(3n) for each for loop n
    // SC : O(1)  as no extra space is used
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
    next_permutation(arr, n);
    return 0;
}

/*

----optimal
1.find the break point
traverse the array from right to check if(arr[i] < arr[i+1])

2.check for edge case || find the next greater number than the index number from right
    swap with the breakpoint index

3.reverse the remaining array
    revers array from index+1 till end

 */