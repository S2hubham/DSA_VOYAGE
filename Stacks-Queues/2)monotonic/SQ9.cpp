#include <bits/stdc++.h>
using namespace std;


// sum of subarray maximums
vector<int> findple(vector<int> arr){
    vector<int> PLE(arr.size(), -1);
    stack<int> st;
    for(int i = 0; i < arr.size(); i++){
        while(!st.empty() && arr[i] > arr[st.top()]){
            st.pop();
        }
        if(!st.empty()){
            PLE[i] = st.top();
        }
        st.push(i);
    }
    return PLE;
    // TC : (2n)
    // SC : O(n)
}

vector<int> findnle(vector<int> arr){
    vector<int> NLE(arr.size(), arr.size());
    stack<int> st;
    for(int i = arr.size()-1; i >= 0; i--){
        while(!st.empty() && arr[i] >= arr[st.top()]){
            st.pop();
        }
        if(!st.empty()){
            NLE[i] = st.top();
        }
        st.push(i);
    }
    return NLE;

    // TC : O(2n)
    // SC : O(n)
}

void sum_subarray_maximuns(vector<int> arr){
    // brute force
    /* int total = 0;
    for(int i = 0; i < arr.size(); i++){
        int maxele = INT_MIN;
        for(int j = i; j < arr.size(); j++){
            maxele = max(arr[j], maxele);
            total += maxele;
        }
    }
    cout<<"Total : "<<total; */

    // TC : O(n^2)
    // SC : O(1)

    
    // better
    int total = 0;
    vector<int> ple = findple(arr);
    vector<int> nle = findnle(arr);
    for(int i = 0; i < arr.size(); i++){
        int left = i - ple[i];
        int right = nle[i] - i;
        total = total + (left * right * arr[i]);
    }
    cout<<"Total : "<<total;

    // TC : O(5n)
    // SC : O(2n)
}


int main(){
    vector<int> arr = {1, 4, 3, 2};
    sum_subarray_maximums(arr);
    return 0;
}