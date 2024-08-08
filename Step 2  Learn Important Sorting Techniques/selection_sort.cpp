#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // keep index of smallest element as first element of iteration
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                // keep index of smallest element after iteration
                min = j;
            }
            // swap(arr[i], arr[min]);
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
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
    selection_sort(arr, n);

    return 0;
}

////--------gfg
int select(int arr[], int i, int n)
{
    int minIndex = i;
    for (int j = i + 1; j < n; j++)
    {
        if (arr[j] < arr[minIndex])
        {
            minIndex = j;
        }
    }
    return minIndex;
}

// Function to perform selection sort
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = select(arr, i, n); // Get the index of the minimum element
        // Swap the found minimum element with the element at index i
        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
        }
    }
}