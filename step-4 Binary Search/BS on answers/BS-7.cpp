#include <bits/stdc++.h>
using namespace std;

// find kth missing positive integer

int missing_no(vector<int> arr, int k)
{
    // brute force
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     if (arr[i] < k)
    //         k++;
    //     else
    //         break;
    // }
    // return k;

    // TC : O(n)


   
    // better
    int n = arr.size();
    // edge case
    if(arr[0] > k) return k;
    cout<<"hi";
    int low = 0, high = n-1;
    while(low <= high){
        int mid = low + (high-low)/2;

        int missing = arr[mid] - (mid+1);
        if(missing < k){
            low = mid + 1;
        }  
        else{
            high = mid - 1;
        }
    }
    return (low + k);

    // TC : O(log n) 
}

int main()
{
    vector<int> arr = {4, 6, 8, 9}; 
    cout <<"Missing integer is : "<< missing_no(arr, 3);
}


/* steps :
1 - find mid
2 - find missing 
3 - check which half to eliminate based on (missing ans k)
4 - low will point to "higher" end of range of ans
    high will point to "lower" end of range of ans
5 - return (low + k) or (high + 1 + k) */