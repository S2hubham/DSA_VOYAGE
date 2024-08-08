#include<bits/stdc++.h>
using namespace std;

//two sun problem
void two_sum_prob(int arr[], int n, int k){
    //---brute force
    /* for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] + arr[j] == k){
                cout<<i+1<<" and "<<j+1<<" elemets addition is "<<k;
                return;
            }
        }
    }
    cout<<"Not possible";

    //TC : O(n2)
    //SC : O(1) */


    //---better
    /* map<int, int> hash;
    for(int i = 0; i < n; i++){
        int a = arr[i];
        int rem = k - a;
        if(hash.find(rem) != hash.end()){
            cout<< hash[rem]+1 <<" and "<< i+1 <<" elemets addition is "<<k;
            return;
        }
        hash[a] = i;
    }
    cout<<"Not possible";

    //TC : O(n logn)
    //SC : O(n) */


    //---optimal only for yes and no (not for inde reurning)
    /* int left = 0;
    int right = n-1;
    sort(arr, arr + n);  //O(n logn)
    while(left < right){  //O(n)
        int sum = arr[left] + arr[right];
        if(sum == k){
            cout<<"YES";
            return;
        }
        else if(sum < k){
            left++;
        }
        else{
            right--;
        }
    }
    cout<<"NO";
    return;

    //TC : O(n)
    //SC : O(1)   (note if distorted array is considered then O(n)) */
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    two_sum_prob(arr, n, 9);

}

/* 
---brute
algo:
compare first element with further elements then second with a further and so on
if sum matches the return the index as i and j


---better
algo:
maintain an hash map
loop through all elements 
calculate the remainig sum 
find the rem in map( if found and not the last element then return the index as hash[rem], i)


---optimal (not for indices)
sort the array
maintain two pointers left and right
loop till the last element
calculate sum = arr[left] + arr[right]
if sum is equal to k ( if found return YES)
if sum is lesser than k then increment left pointer
else increment right pointer
if no sum is equal to k then return NO



 */