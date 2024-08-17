#include <bits/stdc++.h>
using namespace std;

// majority elements II n/3

// approach
// 1 - count variable
// 2 - hashing
// 3 - extended moores voting algo

void majority_II(int arr[], int n)
{
    // brute force
    /* vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (temp.size() == 0 || temp[0] != arr[i])
        { // this prevents checking for same ele which has cnt > n/3
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                }
                if (count > n / 3)
                {
                    temp.push_back(arr[i]);
                    break;
                }
            }
        }
    }
    for (auto it : temp)
    {
        cout << it << " ";
    }
    
    // TC : O(n^2)
    // SC : O(1)
    */



    // better
    // idea : hashing -> number and its appearance
    /* vector<int> ls;
    map<int, int> mpp;
    int min = n/3 + 1;
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
        if(mpp[arr[i]] == min){
            ls.push_back(arr[i]);
        }
        if(ls.size() == 2){
            break;
        }
    }
    for(auto it: ls){
        cout<<it<<" ";
    } */

    // TC : O(n + logn)
    // SC : O(n) 



    // optimal(extension of moores voting algo)
    /* int el1 = INT_MIN, el2 = INT_MIN;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        if(cnt1 == 0 && el2 != arr[i]){
            cnt1 = 1;
            el1 = arr[i];
        }
        else if(cnt2 == 0 && el1 != arr[i]){
            cnt2 = 1;
            el2 = arr[i];
        }
        else if(el1 == arr[i]) cnt1++;
        else if(el2 == arr[i]) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }

    vector<int> temp;
    cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == el1){
            cnt1++;
        }
        if(arr[i] == el2){
            cnt2++;
        }
    }

    if(cnt1 > int(n/3)){
        temp.push_back(el1);
    }
    if(cnt2 > int(n/3)){
        temp.push_back(el2);
    }

    for(auto it: temp){
        cout<<it<<" ";
    }

    // TC : O(2n)
    // SC : O(1) */
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
    majority_II(arr, n);
}