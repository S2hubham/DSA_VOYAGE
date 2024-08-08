#include <bits/stdc++.h>
using namespace std;

// Majority element
void majority(int arr[], int n)
{
    //----brute
    /* for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count > n / 2){
            cout<<"Maximum occurence is of : "<<arr[i]<<endl;
            return;
        }
    }
    cout << "No majority element found." << endl;

    //TC : O(n2)
    //SC : O(1) */

    //---better
    /* map<int, int> hash;
    for(int i = 0; i < n; i++){
        hash[arr[i]]++;         //TC : O(nlogn)
    }
    for(auto it : hash){   //TC : O(n)
        if(it.second > n / 2){
            cout<<"Maximum occurence is of : "<<it.first<<endl;
            return;
        }
    }
    cout << "No majority element found." << endl;

    //TC : O(n + nlogn)
    //SC : O(n)  */


    //----optimal (Moore's voting algo)
    /* int count = 0;
    int element;
    for (int i = 0; i < n; i++)   // TC : O(n)
    { 
        if (count == 0)
        {
            count = 1;
            element = arr[i];
        }
        else if (arr[i] == element)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    // check if majority element exist
    if (element != -1)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)   // TC : O(n)
        { 
            if (arr[i] == element)
            {
                cnt++;
            }
        }
        if (cnt > n / 2)
        {
            cout << "Maximum occurence is of : " << element << endl;
            return;
        }
        cout << "No majority element found." << endl;
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
    majority(arr, n);
}


/* 
--better
traverse through loop 
    traverse through loop to check occurence and increase the count
traverse throung loop to count majority element count > n/2    


----better (use hash map)
traverse through loop 
    increase the count if element exists(in terms of key value pair)
    check for element if count > n/2 if yes -> print element and return


------optimal
apply moores voting algo
    traverse throung the array
    if count is zero -> set count to 1 and element to arr[i]
    if arr[i] == element -> count++
    if arr[i] != element -> count--
if majority element exist then only check for count > n/2

 */