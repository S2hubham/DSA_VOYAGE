#include <bits/stdc++.h>
using namespace std;
#define SIZE 10


// next greater element 2
vector<int> func(vector<int> arr){
    // brute force
    /* int n = arr.size();
    vector<int> nge(n, -1);

    for(int i = 0; i < n; i++){
        int s = n + i;
        for(int j = i+1; j < s; j++){
            int idx = j % n;
            if(arr[i] < arr[idx]){
                nge[i] = arr[idx];
                break;
            }
        }
    }

    return nge;  */
    
    // TC : O(n^2)  -> two loops
    // SC : O(n)    -> nge array




    // better  (using monotonic decreasing order stack)
    /* stack<int> st;
    // for getting previous elements
    for(int i = arr.size()-1; i >= 0; i--){
        while (!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        st.push(arr[i]);
    }
    
    vector<int> ans(arr.size(), -1);
    for(int i = arr.size()-1; i >= 0; i--){
        while (!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }

    return ans; */


    // TC : O(n.) 
    // SC : O(n + n) = O(2n) one for stack and one for ans array
}

int main(){
    vector<int> arr = {2, 10, 12, 1, 11};
    vector<int> ans = func(arr);
    for(int i = 0; i < arr.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
} 