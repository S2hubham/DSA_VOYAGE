#include <bits/stdc++.h>
using namespace std;

// approach
// 1-count variable and iteration
// 2-hashing
// 3-two equation(mathematical) 
// 4-xor method

// find the missing number and repeating number
void miss_and_repeat(vector<int> arr, int n){
    // brute force
    /* int missing = 0;
    int repeating = 0;
    sort(arr.begin(), arr.end());
    for(int i = 1; i <= n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] == i){
                count++;
            }
        }
        if(count == 2){
            repeating = i;
        }
        if(count == 0){
            missing = i;
        }
        if(repeating != 0 && missing != 0){
            break;
        }
    }
    cout<<"missing : "<<missing<<"\nrepeating : "<<repeating; */
    // TC : O(n^2)
    // SC : O(1)


    // better
    // idea : hashing
    /* int missing = -1;
    int repeating = -1;
    map<int, int> hash;
    for(int i = 0; i < n; i++){
        hash[arr[i]]++;
    }
    for(int i = 1; i <= n; i++){
        if(hash[i] == 2){
            repeating = i;
        }
        if(hash[i] == 0){
            missing = i;
        }
    }
    cout<<"missing : "<<missing<<"\nrepeating : "<<repeating;  */
    // TC : O(2n)
    // SC : O(n)


    // optimal - 1
    // mathematical 
    long long SN = (n* (n + 1)) / 2;
    long long S2N = (n* (n + 1) * (2 * n + 1)) / 6;
    long long S = 0;
    long long S2 = 0;
    for(int i = 0; i < n; i++){
        S += arr[i];
        S2 += (long long)arr[i] * (long long)arr[i];
    }

    long long val1 = S - SN; //x - y
    long long val2 = S2 - S2N; // (x+y)(x-y)
    val2 = val2 / val1; //x + y

    long long x = -1, y = -1;
    x = (val1 + val2) / 2;
    y = x - val1;

    cout<<"missing : "<<y<<"\nrepeating : "<<x;

    // TC : O(n)
    // SC : O(1)


    // optimal - 2 (due to overflow in previous approach)
    // idea : XOR
    int xr = 0;
    for(int i = 0 ; i < n; i++){
        xr = xr ^ arr[i];
        xr = xr ^ (i+1);
    }

    int number = xr & ~(xr - 1);
    
    int zero = 0;  //diff differentiating bit club
    int one = 0;   //same differentiating bit club
    // for array elements
    for(int i = 0; i < n; i++){
        if((arr[i] & number) != 0){
            one = one ^ arr[i];
        }
        else{
            zero = zero ^ arr[i];
        }
    }
    // for sequential elements
    for(int i = 1; i <= n; i++){
        if((i & number) != 0){
            one = one ^ i;
        }
        else{
            zero = zero ^ i;
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == zero) count++;
    }
    if(count == 2){
        cout<<"missing : "<< one <<"\nrepeating : "<< zero ;
    }
    else{
        cout<<"missing : "<< zero <<"\nrepeating : "<< one ;
    }

    // TC : O(3n)
    // SC : O(1)
}

int main()
{
    vector<int> arr = {4, 3, 6, 2, 1, 1};
    int n1 = arr.size();
    
    miss_and_repeat(arr, n1);
    return 0;
}

/* 

-find xor of all array elements and sequential elements
-find the diff bit
-club the numbers in 0 and 1
-xor all elements in o and 1 club 
-manually check for repeating and missing


 */