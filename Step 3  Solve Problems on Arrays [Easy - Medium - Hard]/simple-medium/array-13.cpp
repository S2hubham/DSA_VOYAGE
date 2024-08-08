#include <bits/stdc++.h>
using namespace std;

// longest consecutive sequence
void long_consecutive(int arr[], int n){
    //---- brute  
    // TC :  O(n^2)  
    // SC : O(1)



    // ----better
    /* sort(arr, arr + n);
    int last_smaller = INT_MIN;
    int max_len = 1;
    int count = 0;
    for(int i = 0; i < n; i++){
        // check last element
        if(arr[i] - 1 == last_smaller){
            count++;
            last_smaller = arr[i];
        }
        // check for repitition
        if(arr[i] != last_smaller){
            count = 1;
            last_smaller = arr[i];
        }
        max_len = max(count, max_len);
    }
    cout<<"Max consecutive length is : "<<max_len; */

    // TC : O(nlogn + n)
    // SC : O(1)



    //----optimal(constraints )
    /* unordered_set<int> st;
    int longest = 1;
    for(int i = 0; i < n; i++){   //TC : O(n)
        st.insert(arr[i]);
    }
    for(auto it : st){   // TC : O(n)
        // check for first element
        if(st.find(it - 1) == st.end()){
            int cnt = 1;
            int x = it;
            while(st.find(x + 1) != st.end()){   // TC : O(n)
                x++;
                cnt++; 
            }
            longest = max(longest, cnt);
        }
    }
    cout<<"Max consecutive length is : "<<longest; */

    // TC : O(n) + O(n) + O(n)  = O(n)
    // SC : O(1)

}


int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long_consecutive(arr, n);
    return 0;
}




/* 
-----better
sort the array
init last_smaller, lenght, count
iterate through the loop
    if (i-1)th element if equal to the last_smaller -> count++ and last_smaller = ith element
    if ith element != last_smaller ->  count++ and last_smaller = ith element
    determine the length from count and length



-----optimal
insert all array elements in the unordered set
iterate through the set
    check if it is the last/smallest element 
        if yes check how many elements it has next consecutively
        increase count
    set maximun length out of count and length


 */