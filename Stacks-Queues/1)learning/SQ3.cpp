#include <bits/stdc++.h>
using namespace std;

#define SIZE 10

// Stack using queue
class st {
public:
    queue<int> q;

    void push(int x) { 
        int s = q.size();
        q.push(x);

        for (int i = 0; i < s; i++) { 
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    void getTop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element: " << q.front() << endl;
    }
};



// Queue using Stack
class que{
public:
    stack<int> s;
    stack<int> temp;

    // this operation take O(2n) time so if there are lot of push operations then this is bad approach 
    void push(int x){
        while(!s.empty()){
            temp.push(s.top());
            s.pop();
        }
        s.push(x);
        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
    }

    void pop(){
        if(s.empty()){
            cout << "Queue Underflow\n";
            return;
        }
        cout << "Popped: " << s.top() << endl;
        s.pop();
    }

    void getTop(){
        if (s.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Front element: " << s.top() << endl;
    }
};


// better TC
class que2{
public:
    stack<int> s;
    stack<int> temp;

    void push(int x){
        s.push(x);
    }

    void pop() {
        if (temp.empty()) {
            while (!s.empty()) {
                temp.push(s.top());
                s.pop();
            }
        }
        if (temp.empty()) {
            cout << "Queue underflow\n";
            return;
        }
        cout << "Popped: " << temp.top() << endl;
        temp.pop();
    }

    void getTop() {
        if (temp.empty()) {
            while (!s.empty()) {
                temp.push(s.top());
                s.pop();
            }
        }
        if (temp.empty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Front element: " << temp.top() << endl;
    }
}; 



int main() {
    st s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.getTop(); 
    s.pop();    
    s.getTop(); 
    s.push(40);
    s.getTop(); 
    s.pop();    
    s.pop();    
    s.getTop(); 
    s.pop();    
    s.pop();    


    /* que q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.getTop();
    q.pop();
    q.getTop();
    q.push(40);
    q.getTop();
    q.pop();
    q.pop();
    q.getTop();
    q.pop();
    q.pop(); */

    // better approach one
    que2 q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.getTop();
    q.pop();
    q.getTop();
    q.push(40);
    q.getTop();
    q.pop();
    q.pop();
    q.getTop();
    q.pop();
    q.pop();

    return 0;
}



/* 
Diff between que and que2

Aspect	            que (Costly Push Approach)	            que2 (Costly Pop Approach - Optimized)
Push Complexity	    O(2N) (Moves all elements every push)	O(1) (Simply pushes to s)
Pop Complexity	    O(1) (Directly pops from s)	            Amortized O(1), Worst O(N) (Moves only when needed)
Top Complexity	    O(1)	                                Amortized O(1), Worst O(N)
Space Complexity	O(N)	                                O(N)
Best for	        Few push(), frequent pop()	            Frequent push(), fewer pop()

 */