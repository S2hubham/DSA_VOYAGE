#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n)
{
    // Outer loop for the number of passes(n-1)
    for (int i = 0; i < n - 1; i++)
    {
        int didswap = 0;
        // Inner loop for each pass
        for (int j = 0; j < n - i - 1; j++)
        {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1])
            {
                // Swap if elements are in wrong order
                // swap(arr[j], arr[j + 1]);
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                didswap = 1;
            }
        }
        if (didswap == 0)
        {
            break;
        }
        cout << "runs\n";
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
    bubble_sort(arr, n);

    return 0;
}
