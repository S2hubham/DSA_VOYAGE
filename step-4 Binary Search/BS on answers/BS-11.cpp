#include <bits/stdc++.h>
using namespace std;

// minimize max dist to gas stations

int gas_station(vector<int> arr, int stations)
{  
    /* int n = arr.size();
    vector<int> howMany(n-1, 0);
    for(int i = 0; i < stations; i++){
        long double max_dist = -1;
        int max_idx = -1;
        for(int i = 0; i < n-1; i++){
            long double diff = (arr[i+1] - arr[i]);
            long double sectionLen = diff / (long double)(howMany[i] + 1);
            if(sectionLen > max_dist){
                max_dist = sectionLen;
                max_idx = i;
            }
        }
        howMany[max_idx]++;
    }

    long double ans = -1;
    for(int i = 0; i < n-1; i ++){
        long double diff = (arr[i+1] - arr[i]);
        long double sectionLen = diff / (long double)(howMany[i] + 1);
        ans = max(ans, sectionLen);
    }
    return ans; */

    // TC : O(k*n) + O(n)
    // k = gas stations



    // using priority queue 
    // push takes logN 
    int n = arr.size();
    vector<int> howMany(n-1, 0);
    priority_queue<pair<long double, int>> pq;
    for(int i = 0; i < n-1; i++){
        pq.push({arr[i+1]-arr[i], i});
    }
    for(int i = 0; i < stations; i++){
        auto tp = pq.top();
        pq.pop();
        int secIdx = tp.second;
        howMany[secIdx]++;
        long double iniDiff = arr[secIdx+1] - arr[secIdx];
        long double newSecLen = iniDiff / (long double)(howMany[secIdx]+1);
        pq.push({newSecLen, secIdx});
    }
    return pq.top().first;

    // TC : O(n logn) + O(k logn)
}

int main()
{
    vector<int> arr = {1, 13, 17, 23}; 
    cout <<"Max distance is : "<< gas_station(arr, 5);
}


/* 

steps for first
A : 
    1-iterate for all gas stations that needs to be placed
    2-iterate through all elements of given array
        find diff between consecutive elements
        divide diff by n0. of already placed station + 1 (one more as space gets divide by 2)
        hold the maximum section length and corresponding index
    3-add 1 more to the corresponding index
B :
    1-iterate through all elements of given array
        find diff between consecutive elements
        divide diff by n0. of already placed station + 1 (one more as space gets divide by 2)
        hold the max section length and return it  


 */