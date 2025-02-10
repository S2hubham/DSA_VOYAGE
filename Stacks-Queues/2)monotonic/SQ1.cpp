#include <bits/stdc++.h>
using namespace std;
#define SIZE 10


// next greater element
vector<int> func(vector<int> arr){
    // brute force
    /* vector<int> nge(arr.size(), -1);

    for(int i = 0; i < arr.size(); i++){
        for(int j = i+1; j < arr.size(); j++){
            if(arr[i] < arr[j]){
                nge[i] = arr[j];
                break;
            }
        }
    }

    return nge; 
    
    // TC : O(n^2)  -> two loops
    // SC : O(n)    -> nge array
    */


    // better  (using monotonic decreasing order stack)
    stack<int> st;
    vector<int> nge(arr.size(), -1);
    for(int i = (arr.size()-1); i >= 0; i--){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            nge[i] = st.top();
        }
        st.push(arr[i]);
    }
    return nge;

    // TC : O(n)
    // SC : O(n)
}

int main(){
    vector<int> arr = {6, 0, 8, 1, 3};
    vector<int> ans = func(arr);
    for(int i = 0; i < arr.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
} 