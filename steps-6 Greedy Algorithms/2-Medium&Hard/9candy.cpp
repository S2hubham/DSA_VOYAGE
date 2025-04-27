#include<bits/stdc++.h>
using namespace std;

// candy 
int func(vector<int> arr){
    // brute force
    /* int n = arr.size(), candies = 0;
    vector<int> left(n, -1);
    vector<int> right(n, -1);
    

    left[0] = 1;
    for(int i = 1; i < n; i++){
        if(arr[i-1] < arr[i]){
            left[i] = left[i-1]+1;
        }
        else{
            left[i] = 1;
        }
    }

    right[n-1] = 1;
    for(int i = n-2; i >= 0; i--){
        if(arr[i] > arr[i+1]){
            right[i] = right[i+1]+1;
        }
        else{
            right[i] = 1;
        }
    }

    for(int i = 0; i < n; i++){
        candies += max(left[i], right[i]);
    }

    return candies; */

    // TC : O(3n)
    // SC : O(2n)


    // better
    /* int n = arr.size(), candies = 0;
    vector<int> left(n, -1);    

    left[0] = 1;
    for(int i = 1; i < n; i++){
        if(arr[i-1] < arr[i]){
            left[i] = left[i-1]+1;
        }
        else{
            left[i] = 1;
        }
    }

    int right = 1, curr = 1; 
    candies = max(1, left[n-1]);
    for(int i = n-2; i >= 0; i--){
        if(arr[i] > arr[i+1]){
            curr = right + 1;
            right += 1;
        }
        else{
            curr = 1;
            right = 1;
        }
        candies += max(left[i], curr);
    }

    return candies; */

    // TC : O(2n)
    // SC : O(n)


    // optimal
    int n = arr.size(), i = 1, sum = 1;
    while(i < n){
        // check for flat
        if(arr[i] == arr[i-1]){
            sum += 1;
            i++;
            continue;
        }

        // check for increasing slope
        int peak = 1;
        while(i < n && arr[i] > arr[i-1]){
            peak += 1;
            sum += peak;
            i++;
        }

        // check for decreasing slope
        int down = 1;
        while(i < n && arr[i] < arr[i-1]){
            sum += down;
            down += 1;
            i++;
        }

        if(down > peak){
            sum += down - peak;
        }
    }
    return sum;

    // TC : O(n)
    // SC : O(1)
}


int main(){
    vector<int> candy = {1, 3, 2, 1};  // 7
    vector<int> candy1 = {0, 2, 4, 3, 2, 1, 1, 3, 5, 6, 4, 0, 0};  // 27
    cout<<"Max no. of candies required are : "<<func(candy);
    return 0;
}