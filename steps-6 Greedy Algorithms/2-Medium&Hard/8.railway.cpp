#include<bits/stdc++.h>
using namespace std;


// Minimum number of platforms required for a railway
int func(vector<int> arr, vector<int> dep){
    // brute for check with each for all
    /* int n = arr.size(), maxCnt = 0;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(arr[i] <= dep[j] && arr[j] <= dep[i]){
                cnt++;
            }
            maxCnt = max(maxCnt, cnt);
        }
    }
    return maxCnt; */

    // TC : O(n^2)
    // SC : O(1)


    // better approach
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int l = 0, r = 0, n1 = arr.size(), n2 = dep.size(), maxcnt = 0, cnt = 0;

    while(l < n1){
        if(arr[l] <= dep[r]){
            cnt++;
            l++;
        }
        else{
            cnt--;
            r++;
        }
        maxcnt = max(maxcnt, cnt);
    }

    return maxcnt;
    // TC : O(2*nlogn + 2n)
    // SC : O(1)
}


int main(){
    vector<int> arrival = {900, 945, 955, 1100, 1500, 1800};
    vector<int> departure = {920, 1200, 1130, 1150, 1900, 2000};

    cout<<"Minimum no. of platforms required are : "<<func(arrival, departure);
    return 0;
}