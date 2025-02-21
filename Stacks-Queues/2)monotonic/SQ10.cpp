#include <bits/stdc++.h>
using namespace std;


// largest rectangle in histogram 
vector<int> findpse(vector<int> arr){
    vector<int> PSE(arr.size(), -1);
    stack<int> st;
    for(int i = 0; i < arr.size(); i++){
        while(!st.empty() && arr[i] < arr[st.top()]){
            st.pop();
        }
        if(!st.empty()){
            PSE[i] = st.top();
        }
        st.push(i);
    }
    return PSE;
    // TC : (2n)
    // SC : O(n)
}

vector<int> findnse(vector<int> arr){
    vector<int> NSE(arr.size(), arr.size());
    stack<int> st;
    for(int i = arr.size()-1; i >= 0; i--){
        while(!st.empty() && arr[i] <= arr[st.top()]){
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

void max_reactangle(vector<int> arr){
    // brute
    /* int maxi = 0;
    vector<int> pse = findpse(arr);
    vector<int> nse = findnse(arr);
    for(int i = 0; i < arr.size(); i++){
        int area = arr[i] * (nse[i] - pse[i] - 1);
        maxi = max(maxi, area);
    }
    cout<<"Maximum Rectangle in histogram is  : "<<maxi; */

    // TC : O(5n)
    // SC : O(4n)



    // better (no precomputation)
    stack<int> st;
    int maxArea = 0;
    for(int i = 0; i < arr.size(); i++){
        while(!st.empty() && arr[i] < arr[st.top()]){
            int ele = arr[st.top()];
            st.pop();
            int nse = i;
            int pse = (!st.empty()) ? st.top() : -1;
            int area = ele * (nse - pse - 1);
            maxArea = max(maxArea, area);
        }
        st.push(i);
    }
    while(!st.empty()){
        int ele = arr[st.top()];
        st.pop();
        int nse = arr.size();
        int pse = (!st.empty()) ? st.top() : -1;
        int area = ele * (nse - pse - 1);
        maxArea = max(maxArea, area);
    }
    cout<<"Maximum Rectangle in histogram is : "<<maxArea;

    // TC : O(n + n) one for for loop one for each elements push/pop 
    // SC : O(n) in worst case all indices might be pushed on stack 
}


int main(){
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    vector<int> a = {3, 2, 10, 11, 5, 10, 6, 3};
    max_reactangle(arr);
    return 0;
}