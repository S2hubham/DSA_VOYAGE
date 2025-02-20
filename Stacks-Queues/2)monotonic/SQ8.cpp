#include <bits/stdc++.h>
using namespace std;


// sum of subarray ranges

// maximums
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


// minimums
vector<int> findnse(vector<int> arr){
    stack<int> st;
    vector<int> NSE(arr.size(), arr.size());
    for(int i = arr.size()-1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            NSE[i] = st.top();
        }
        st.push(i);
    }
    return NSE;
    // TC : O(2n)
    // SC : O(n)
}


vector<int> findpse(vector<int> arr){
    stack<int> st;
    vector<int> PSE(arr.size(), -1);
    for(int i = 0; i < arr.size(); i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        if(!st.empty()){
            PSE[i] = st.top();
        }
        st.push(i);
    }
    return PSE;
    // TC : O(2n)
    // SC : O(n)
}


void sum_subarray_ranges(vector<int> arr){
    // brute force
    /* int total = 0;
    for(int i = 0; i < arr.size(); i++){
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int j = i; j < arr.size(); j++){
            mini = min(arr[j], mini);
            maxi = max(arr[j], maxi);
            int range = maxi - mini;
            total += range;
        }
    }
    cout<<"Total : "<<total; */

    // TC : O(n^2)
    // SC : O(1)

    

    // better -> combo of both maximumns ans minimums
    int total = 0;
    vector<int> nse = findnse(arr);
    vector<int> pse = findpse(arr);
    vector<int> nle = findnle(arr);
    vector<int> ple = findple(arr);
    for(int i = 0; i < arr.size(); i++){
        int leftmax = i - ple[i];
        int rightmax = nle[i] - i;
        int leftmin = i - pse[i];
        int rightmin = nse[i] - i;
        int totalmax = leftmax * rightmax * arr[i];
        int totalmin = leftmin * rightmin * arr[i];
        total += totalmax - totalmin;
    }

    cout<<"Total : "<<total;

    // TC : O(10n)
    // SC : O(8n)
}

int main(){
    vector<int> arr = {1, 4, 3, 2};
    sum_subarray_ranges(arr);
    return 0;
}