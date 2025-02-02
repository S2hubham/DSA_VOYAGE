#include <bits/stdc++.h>
using namespace std;

#define SIZE 10

class Node{
public:
    int data;
    Node* next;

    Node(){
        data = 0;
        next = NULL;
    }

    Node(int d){
        this->data = d;
        this->next = NULL;
    }
}; 


// Stack-Queue Implementation using LL
class stack_ll{
    Node* top = NULL;
    int currsize = 0;

public:
    void push(int x){
        if(currsize == SIZE){
            cout<<"Stack Overflow\n";
            return;
        }
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        currsize += 1;
    }

    void pop(){
        if(currsize == 0){
            cout<<"Stack Underflow\n";
            return;
        }
        Node* delNode = top;
        cout<<"Last deleted item is : "<<delNode->data;
        top = top->next;
        delNode->next = NULL;
        delete delNode;
        currsize -= 1;
    }

    void getTop(){
        if(currsize == 0){
            cout<<"Empty stack no top element\n";
            return;
        }
        cout<<"Top element is : "<<top->data<<endl;
    }

    void getSize(){
        cout<<"Stack size is : "<<currsize<<endl;
    }
};



class Queue_ll{
    int currsize = 0;
    Node* start = NULL;
    Node* end = NULL;

public :
    void push(int x){
        if(currsize == SIZE){
            cout<<"Queue Overflow\n";
            return;
        }
        Node* newNode = new Node(x);
        if(start == NULL && end == NULL){
            start = newNode;
        }
        else{
            end->next = newNode;
        }
        end = newNode;
        currsize += 1;
    }

    void pop(){
        if(currsize == 0){
            cout<<"Queue underflow\n";
            return;
        }
        Node* delNode = start;
        cout << "Last deleted item is: " << delNode->data << endl;
        if(currsize == 1){
            start = NULL;
            end = NULL;
        }
        else{
            start = start->next;
        }
        delNode->next = NULL;
        delete delNode;
        currsize -= 1;
    }

    void getTop(){
        if(currsize == 0){
            cout<<"Queue is empty no top element\n";
            return;
        }
        cout<<"Top element is : "<<start->data<<endl;
    }

    void getSize(){
        cout<<"Size of queue is : "<<currsize<<endl;
    }
};


int main() {
    /* stack_ll st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.getTop();
    st.getSize();
    st.pop();
    st.push(40);
    st.getTop();
    st.push(50);
    st.pop();
    st.getSize();
    st.push(60);
    st.pop();
    st.pop();
    st.getTop();
    st.getSize(); */


    /* Queue_ll q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.getTop();
    q.getSize();
    q.pop();
    q.push(40);
    q.getTop();
    q.push(50);
    q.pop();
    q.getSize();
    q.push(60);
    q.pop();
    q.pop();
    q.getTop();
    q.getSize(); */


    return 0;
}
