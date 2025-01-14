#include <bits/stdc++.h>
using namespace std;

// sort an stack recursively
void func(stack<int> &st, int value){
    // base case
    if (st.empty() || st.top() <= value) {
        st.push(value); 
        return;
    }

    int topele = st.top();
    st.pop(); 
    func(st, value);
    st.push(topele); 
}

void sort_stack(stack<int> &st){
    /* vector<int> arr;
    while(!st.empty()){
        arr.push_back(st.top());
        st.pop();
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++){
        st.push(arr[i]);
    } */

    // TC : O(nlogn)
    // SC : O(n)



    // recursive approach
    // base case
    if(st.empty()){
        return;
    }
    int topele = st.top();
    st.pop();
    sort_stack(st);
    func(st, topele);

    // TC : O(n^2)
    // SC : O(n)
}

int main()
{
    stack<int> st;
    st.push(90);
    st.push(20);
    st.push(30);
    st.push(100);
    sort_stack(st);
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
