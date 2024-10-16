#include <bits/stdc++.h>
using namespace std;

// median of two sorted arrays

int median(vector<int> arr1, vector<int> arr2)
{  
    // brute force
    /* int n1 = arr1.size(), n2 = arr2.size();
    int n = n1 + n2;
    vector<int> ans;
    int i = 0, j = 0;
    while(i < n1 && j < n2){
        if(arr1[i] <= arr2[j]){
            ans.push_back(arr1[i++]);
        }
        else{
            ans.push_back(arr2[j++]);
        }
    }
    while(i < n1){
        ans.push_back(arr1[i++]);
    }
    while(j < n2){
        ans.push_back(arr2[j++]);
    }

    if(n % 2 != 0){
        return ans[n/2];
    }
    else{
        return (ans[n/2] + ans[(n/2)-1]) / 2;
    }
    return -1;

    // TC : O(n1 + n2)
    // SC : O(n1 + n2) */


    // better
    /* int n1 = arr1.size(), n2 = arr2.size();
    int n = n1 + n2;
    vector<int> ans;
    int i = 0, j = 0;
    int idx1 = n/2 - 1, idx2 = n/2;
    int cnt = 0, idx1el = 0, idx2el = 0;
    while(i < n1 && j < n2){
        if(arr1[i] <= arr2[j]){
            if(cnt == idx1) idx1el = arr1[i];
            if(cnt == idx2) idx2el = arr1[i];
            cnt++;
            i++;
        }
        else{
            if(cnt == idx1) idx1el = arr2[j];
            if(cnt == idx2) idx2el = arr2[j]; 
            cnt++;
            j++;
        }
    }
    while(i < n1){
        if(cnt == idx1) idx1el = arr1[i];
        if(cnt == idx2) idx2el = arr1[i]; 
        cnt++;
        i++;
    }
    while(j < n2){
        if(cnt == idx1) idx1el = arr2[j];
        if(cnt == idx2) idx2el = arr2[j];
        cnt++;
        j++;
    }

    if(n % 2 != 0){
        return idx2el;
    }
    else{
        return (idx1el + idx2el) / 2;
    }
    return -1; */

    // TC : O(n1 + n2)
    // SC : O(1)


    // best
    int n1 = arr1.size(), n2 = arr2.size();
    int n = n1 + n2;
    if(n1 > n2) return median(arr2, arr1);
    // symmetry formula
    int x = (n1 + n2 + 1)/2;
    int low = 0, high = n1;
    while(low <= high){
        int mid1 = low + (high - low) / 2;
        int mid2 = x - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid1 - 1 >= 0) l1 = arr1[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = arr2[mid2 - 1];
        if(mid1 < n1) r1 = arr1[mid1];
        if(mid2 < n2) r2 = arr2[mid2];
        if(l1 <= r2 && l2 <= r1){
            if(n % 2 != 0) return max(l1, l2);
            else{
                return (max(l1, l2) + min(r1, r2)) / 2;
            }
        } 
        else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return -1;

    // TC : O(min(n1, n2))
    // SC : O(1)
}

int main()
{
    vector<int> arr1 = {1, 3, 4, 7, 10, 12}; 
    vector<int> arr2 = {2, 3, 6, 15};
    cout <<"Median is : "<< median(arr1, arr2);
}