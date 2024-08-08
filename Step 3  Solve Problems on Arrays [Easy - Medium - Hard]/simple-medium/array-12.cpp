#include <bits/stdc++.h>
using namespace std;

// leaders in an array
void leader(int arr[], int n){
    // ----brute force
    /* vector<int> ans;
    for(int i = 0; i < n; i++){
        bool flag = true;
        for(int j = i+1; j < n; j++){
            if(arr[i] < arr[j]){
                flag = false;
                break;
            }
        }
        // check all the elements are smaller to its right
        if(flag == true){
            ans.push_back(arr[i]);
        }
    }
    for(auto it : ans){
        cout<<it<< " ";
    }

    // TC ~ O(n^2)
    // SC : O(n) */


    // -----optimal 
    /* int maxi = INT_MIN;
    vector<int> ans;
    for(int i = n-1; i >= 0; i--){
        if(arr[i] > maxi){
            maxi = arr[i];
            ans.push_back(maxi);
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto it : ans){
        cout<<it<< " ";
    } */

    // TC : O(n)
    // SC : O(n)
}


int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    leader(arr, n);
    return 0;
}


/* 
---brute
Initialization: Create an empty result vector ans.
Outer Loop: For each element in the array. Assume it is the largest element to the right.
Inner Loop: Compare it with each subsequent element. If a larger element is found, mark it as not the largest.
Check and Store: If no larger element is found to the right, store the current element in ans.
Output: Print all elements stored in ans.



--optimal
init : maximum = INT_MIN, ans vector
iterate the array from end to start
    if arr[i] > maximum -> maximum = arr[i] ans store the maximum in the ans vector 



 */