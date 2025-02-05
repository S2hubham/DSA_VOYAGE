#include <bits/stdc++.h>
using namespace std;
#define SIZE 10


// mini stack
/* class stack_mini{
public:
    stack<pair<int, int>> st;

    void Push(int x){
        if(st.empty()){
            st.push({x, x});
        }
        else{
            st.push({x, mini(x, st.top().second)});
        }
    }

    void pop(){
        if(!st.empty()){
            st.pop();
        }
    }

    void getTop(){
        cout<<st.top().first<<endl;
    }

    void getmini(){
        cout<<st.top().second<<endl;
    }

    // TC : O(1)
    // SC : O(2n) ~= O(n)
}; */


// better SC
class stack_mini{
public:
    stack<int> st;
    int mini = INT_MAX;

    void Push(int x) {
        if (st.empty()) { 
            mini = x;
            st.push(x);
        } 
        else if (x < mini) {  
            int newVal = 2 * x - mini;
            mini = x;
            st.push(newVal);
        } 
        else {
            st.push(x);
        }
    }


    void pop(){
        if(!st.empty()){
            if(st.top() < mini){
                cout<<"Last deleted element is : "<<mini<<endl;
                mini = 2 * mini - st.top();
            }
            else{
                cout<<"Last deleted element is : "<<st.top()<<endl;
            }
            st.pop();
        }
        else{
            cout<<"stack underflow\n";
        }
    }

    void getTop(){
        if(!st.empty()){
            if(st.top() < mini){
                cout<<"Top element is : "<<mini<<endl;
            }
            else{
                cout<<"Top element is : "<<st.top()<<endl;
            }
        }
        else{
            cout<<"No top element as stack is empty\n";
        }
    }

    void getmini(){
        cout<<"mini element is : "<<mini<<endl;
    }

    // TC : O(1)
    // SC : O(2n) ~= O(n)
};

int main(){
    stack_mini st;
    st.Push(12);
    st.Push(15);
    st.Push(10);
    st.getmini();
    st.pop();
    st.getmini();
    st.getTop();
    st.Push(10);
    st.getmini();
    return 0;
}