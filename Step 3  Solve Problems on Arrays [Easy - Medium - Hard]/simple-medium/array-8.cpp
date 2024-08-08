#include <bits/stdc++.h>
using namespace std;

//maximum subarray sum
void max_subarray_sum(int arr[], int n){
    //-----brute force(get all subarrays and find max sum)
    /* int sum = 0;
    int maximum = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            sum = 0;
            for(int k = i; k <= j; k++){
                sum += arr[k];
            }
            maximum = max(sum, maximum);
        }
    }
    cout<<"Maximum subarray addition is : "<<maximum;

    //TC : O(n^3)
    //SC : O(1) */


    //----better
    /* int sum = 0;
    int maximum = INT_MIN;
    for(int i = 0; i < n; i++){
        sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            maximum = max(sum, maximum);
        }
    }
    cout<<"Maximum subarray addition is : "<<maximum;

    // TC : O(n2)
    // SC : O(1) */


    //------optimal (Kadane's algo)
    int sum = 0;
    int maximum = INT_MIN;
    int begg = -1;
    int start = -1;
    int end = -1;
    for(int i = 0; i < n; i++){
        if(sum == 0){
            begg = i;
        }

        sum += arr[i];

        if(sum > maximum){
            maximum = sum; 
            start = begg;
            end = i;
        }

        if(sum < 0){
            sum = 0;
        }
    }
    // if none of their addition is greater than 0
    if(maximum < 0){
        maximum = 0;
    }
    cout<<"Maximum subarray addition is : "<<maximum<<endl;

    for(int i = start; i <= end; i++){
        cout<<arr[i]<<" ";
    }

    // TC : O(n)
    // SC : O()

}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    max_subarray_sum(arr, n);
}


/* 
-----better
find all sub arrays with two loops iterations
then calculate sum for each new element and check for maximum

----optimal
init sum to zero and maximum to lowest value
traverse through loop
calculate sum by adding each element
    if sum == zero -> begg
    if sum > maximum -> maximum = sum , start = begg, end = i
    if sum < zero -> sum = 0
 */