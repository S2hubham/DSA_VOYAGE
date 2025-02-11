#include <bits/stdc++.h>
using namespace std;
#define SIZE 10


// previous smaller element
vector<int> func(vector<int> arr){
    // brute force
    /* int n = arr.size();
    vector<int> pse(n, -1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                pse[i] = arr[j];
            }
        }
    }

    return pse;  */
    
    // TC : O(n^2)  -> two loops
    // SC : O(n)    -> pse array




    // better  (using monotonic increasing order)
    stack<int> st;
    vector<int> ans(arr.size(), -1);
    for(int i = 0; i < arr.size(); i++){
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    return ans;


    // TC : O(n + n) = O(2n) one for for loop and other for at max poping all elements from stack  
    // SC : O(n + n) = O(2n) one for stack and one for ans array
}

int main(){
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> ans = func(arr);
    for(int i = 0; i < arr.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
} 