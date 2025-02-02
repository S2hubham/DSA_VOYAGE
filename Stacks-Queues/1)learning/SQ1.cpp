#include <bits/stdc++.h>
using namespace std;

#define SIZE 20  

// Stack-Queue Implementation using Array
class ST_array {
    int st[SIZE], top = -1;  

public:
    void push(int x) {
        if (top == SIZE - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        top += 1;
        st[top] = x;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Last element is deleted: " << st[top] << endl;
        top -= 1;
    }

    void getTop() { 
        if (top == -1) {
            cout << "No top element\n";
            return;
        }
        cout << "Top element is: " << st[top] << endl;
    }

    void getSize() {  
        cout << "Size is: " << top + 1 << endl;
    }

    // TC : O(1)
    // SC : O(SIZE)
};



class Queue_array{
    int q[SIZE], currsize = 0, start = -1, end = -1;

public: 
    void push(int x){ 
        if(currsize == SIZE){
            cout<<"Queue Overflow";
            return;
        }
        if(currsize == 0){
            start += 1;
        } 
        end = (end + 1) % SIZE;
        q[end] = x;
        currsize += 1;
    }

    void pop(){
        if(currsize == 0){
            cout << "Queue Underflow\n";
            return;
        }
        int ele = q[start];
        if(currsize == 1){
            start = end = -1;
        }
        cout<<"Last element is deleted: " << ele << endl;
        start = (start + 1) % SIZE;
        currsize -= 1;
    }

    void getTop(){
        if(start == -1){
            cout << "No top element\n";
            return;
        }
        cout<< "Top element is: " << q[start] << endl;
    }

    void getSize(){
        cout<<"Size is: " << currsize << endl;
    }


    // TC : O(1)
    // SC : O(SIZE)
};






int main() {
    // ---array---

    /* ST_array st; 

    st.push(10);
    st.push(20);
    st.push(30);
    st.pop();      
    st.push(40);
    st.getTop();   
    st.push(50);
    st.pop();      
    st.push(60);
    st.getTop();   
    st.getSize();  
    st.pop();      
    st.pop();      
    st.getTop();  
    st.getSize();   */


    /* Queue_array q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.getTop();
    q.getSize();
    q.pop();
    q.push(40);
    q.push(50);
    q.getTop();
    q.pop();
    q.getSize();
    q.push(60);
    q.push(70);
    q.pop();
    q.pop();
    q.getTop();
    q.getSize(); */


    return 0;
}
