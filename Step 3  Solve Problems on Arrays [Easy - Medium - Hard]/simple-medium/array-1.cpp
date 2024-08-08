#include <bits/stdc++.h>
using namespace std;

// largest element in array
void largest(int arr[], int n)
{
    int largest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    cout << "Largest Element in the array is " << largest;
}

// second largest
void s_largest(int arr[], int n)
{
    // int largest = arr[0];
    // for (int i = 1; i < n; i++)
    // {
    //     if (arr[i] > largest)
    //     {
    //         largest = arr[i];
    //     }
    // }
    // cout << "Largest Element in the array is " << largest << endl;
    // int s_largest = INT_MIN;
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] != largest && arr[i] > s_largest)
    //     {
    //         s_largest = arr[i];
    //     }
    // }
    // cout << "Second largest Element in the array is " << s_largest;
    // // TC = O(n + n) bcoz of two loops

    // optimal solution
    int largest = arr[1];
    int s_largest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            s_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > s_largest)
        {
            s_largest = arr[i];
        }
    }
    cout << "Largest " << largest << "\nSecond largest " << s_largest;

    //TC : O(n)  dur to one pass only
}

//smallest element in array
void smallest(int arr[], int n)
{
    int smallest = arr[1];
    for(int i = 0; i < n; i++){
        if(arr[i] < smallest){
            smallest = arr[i];
        }
    }
    cout<<"smallest "<<smallest;
}

//second smallest
void s_smallest(int arr[], int n)
{
    int smallest = arr[1];
    int s_smallest = INT_MAX;
    for(int i = 0; i < n; i++){
        if(arr[i] < smallest){
            s_smallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] > smallest && arr[i] < s_smallest){
            s_smallest = arr[i];
        }
    }
    cout<<"Smallest "<<smallest <<" Second smallest " << s_smallest;
    //TC : O(n)  dur to one pass only
}


//check if array is sorted
int sorted(int arr[], int n){
    for(int i = 1; i < n; i++){
        if(arr[i] > arr[i+1]){
            return 0;
        }
    }
    return 1;
} 

//unique characters
void chars(int arr[], int n){
    // set<int> temp;
    // for(int i = 0; i < n; i++){ //TC : O(n)
    //     temp.insert(arr[i]);  //TC : nlog(n) for inserion
    // }
    // int unique = temp.size();
    // cout<<"Unique elements "<<unique <<endl;
    // for(auto it : temp){
    //     cout<<it <<" ";
    // }

    //TC : O(nlog(n) + n)
    //SC : O(n)  if all elements are unique


    //optimal solution
    int i = 0;
    for(int j = 1; j < n; j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    i++;
    cout<<"Unique elements " << i;
     
    //TC : O(n) due to single loop
    //SC : O(1) as only one shifting is done
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
    // largest(arr, n);
    // s_largest(arr, n);
    // smallest(arr, n);
    // s_smallest(arr, n);
    // int ans = sorted(arr, n);
    // if(ans == 0) cout<<"unsorted";
    // if(ans == 1) cout<<"Sorted";
    chars(arr, n);
}