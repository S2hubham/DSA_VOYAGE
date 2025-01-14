#include <bits/stdc++.h>
using namespace std;

// reverse a stack using recursion

void insert_bottom(stack<int> &st, int value){
    // base case
    if(st.empty()){
        st.push(value);
        return;
    }
    int topele = st.top();
    st.pop();
    insert_bottom(st, value);
    st.push(topele);
}

void reverse(stack<int> &st)      // TC : O(n)
{
    // base case
    if(st.empty()){
        return;
    }
    int topele = st.top();
    st.pop();
    reverse(st);
    insert_bottom(st, topele);   // TC : O(n)

    // TC : O(n^2)
    // SC : O(n)
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    reverse(st);
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
