#include <bits/stdc++.h>
using namespace std;

// aggresive cows

bool canWePlace(vector<int> arr, int mid, int cows){
    int cntCows = 1, last = arr[0];
    for(int i = 1; i < arr.size(); i++){
        if((arr[i] - last) >= mid){
            cntCows += 1;
            last = arr[i];
        }
        if(cntCows >= cows)
            return 1;
    }
    return (cntCows >= cows);
}

int missing_no(vector<int> arr, int cows)
{  
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int low = 1, high = (arr[n-1] - arr[0]); //set the range
    while (low <= high)
    {
        int mid = low + (high - low)/2;

        if(canWePlace(arr, mid, cows)){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return high;
    
}

int main()
{
    vector<int> arr = {0, 3, 4, 7, 10, 9}; 
    cout <<"Missing distance is : "<< missing_no(arr, 4);
}

/* 

steps
1 : set the low and high range
2 : check whether the given min dist can be max or not 
    if yes -> inc low
    if no -> dec high
3 : return high 

func : inc cows count if dist bet last and curr stall is >= mid 
 */