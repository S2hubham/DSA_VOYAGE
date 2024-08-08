#include <bits/stdc++.h>
using namespace std;

// missing number
void missing(int arr[], int N)
{
    //----- brute force
    /*for(int i = 1; i <= n; i++){
        int flag = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] == i){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout<< i <<" is not present\n";
            return;
        }
    }

    //TC : O(n*n)
    //SC : O(1)*/

    //-----better
    /*int hash[N+1] = {0};
    for(int i = 0; i < N-1; i++){
        hash[arr[i]] = 1;
    }
    for(int i = 1; i <= N; i++){
        if(hash[i] == 0){
            cout<<"Missing elements is : "<<i;
        }
    }
    //TC : O(N*N)
    //SC : O(N)*/

    /*int n = nums.size();
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;
    for (int num : nums) {
        actualSum += num;
    }
    return expectedSum - actualSum;*/

    //----optimal
    /*int n = N - 1;
    int xor1 = 0;
    int xor2 = 0;
    for(int i = 0; i < n; i++){
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i+1);
    }
    xor1 = xor1 ^ N;
    int ans = xor1 ^ xor2;
    cout<<"Missing elements is : "<<ans;

    //TC : O(n)*/
}


void max_cons_ones(int arr[], int n)
{
    int max_count = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count++;
        }
        else
        {
            if (count > max_count)
            {
                max_count = count;
            }
            count = 0;
        }
    }

    // Handle the case where the array ends with a sequence of 1s
    if (count > max_count)
    {
        max_count = count;
    }
    cout << "maximum consecutive ones are : " << max_count;

    //TC : O(n)
}

void appear_once(int arr[], int n){
    int xor1 = arr[0];
    for(int i = 1; i < n; i++){
        xor1 = xor1 ^ arr[i];
    }
    cout<<"Elements appearing once is : "<<xor1;
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
    // missing(arr, n);
    // max_cons_ones(arr, n);
    appear_once(arr, n);
}