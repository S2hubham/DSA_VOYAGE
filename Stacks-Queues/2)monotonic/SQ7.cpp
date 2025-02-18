#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)

// sum of subarray minimums
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


void sum_subarray_min(vector<int> arr){
    // brute force
    /* int total = 0;
    for(int i = 0; i < arr.size(); i++){
        int minele = INT_MAX;
        for(int j = i; j < arr.size(); j++){
            minele = min(minele, arr[j]);
            total += minele;
        }
    } 
    cout<<"Total : "<<total; */

    // TC : O(n^2)
    // SC : O(1)



    // better
    vector<int> nse = findnse(arr);
    vector<int> pse = findpse(arr);
    long long total = 0;
    for(int i = 0; i < arr.size(); i++){
        long left = i - pse[i];
        long right = nse[i] - i;
        total = (total + (left * right % MOD) * arr[i] % MOD) % MOD;
    }
    cout<<"Total : "<<(int)(total % MOD);

    // TC : O(5n)
    // SC : O(2n)
}

int main(){
    vector<int> arr = {1, 1};
    sum_subarray_min(arr);
    return 0;
} 