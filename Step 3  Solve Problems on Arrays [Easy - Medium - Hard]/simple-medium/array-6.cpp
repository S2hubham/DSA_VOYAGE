#include <bits/stdc++.h>
using namespace std;

// sort an array of 0 1 and 2
void sort_012(int arr[], int n)
{
    //----brute force
    /* int count0 = 0;
    int count1 = 0; 
    int count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            count0++;
        else if (arr[i] == 1)
            count1++;
        else
            count2++;
    }
    // for 0
    for (int i = 0; i < count0; i++)
    {
        arr[i] = 0;
    }
    // for 1
    for (int i = count0; i < count0 + count1; i++)
    {
        arr[i] = 1;
    }
    // for 2
    for (int i = count0 + count1; i < n; i++)
    {
        arr[i] = 2;
    }

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }

    //TC : O(n + n)
    //SC : O(1) */


    //----optimal (Dutch National Flag algo)
    /* int low = 0; 
    int mid = 0;
    int high = n-1;
    while(mid <= high){
        // case 1
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        // case 2
        else if(arr[mid] == 1){
            mid++;
        }
        //case 3
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    } */
    //TC : O(n)  The time complexity of this algorithm is O(n), where n is the number of elements in the array. This is because each element is processed exactly once. The pointers low, mid, and high traverse the array in a single pass.
    //SC : O(1)

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
    sort_012(arr, n);
}



/* 
---brute
get three pointers for 0, 1, 2
traverse the array 
find counts of 0, 1, 2
run the for loop till their counts(0, 1, 2) and insert in the array



----optimal(Dutch)
(0 - low-1 == 0,   low to mid-1 == 1,  mid to high == unsorted,  high+1 to n-1 == 2)
get three pointers (low and mid at 0 index and high at last index of array)
traverse the array till the mid <= high (as we are moving in terms of mid)
conditions : 1 - if([mid] == 0){
                swap(arr[low], arr[mid])
                low++ and mid++
             2 - else if(arr[mid] == 1)
                    mid++
             3 - else
                    swap(arr[mid], arr[high]);
                    high--

 */