#include <bits/stdc++.h>
using namespace std;


// Reverse a LL

class Node
{
public:
    int data;
    Node *next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterized Constructor
    Node(int data)
    {
        // this ensure that actual value is passed and not the memory location
        this->data = data;
        this->next = NULL;
    }
};

Node *constructLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp; 
        mover = temp;       
    }

    return head;
}


void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


// Iterative 
Node* reverseLL(Node* head){
    // brute  (using stack)
    /* stack<int> st;
    Node* temp = head;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    
    temp = head;
    while(temp != NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head; */

    // TC : O(n)
    // SC : O(n)


    // better
    /* Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        head = temp;
        temp = front;
    }
    return head; */

    // TC : O(n)
    // SC : O(1)
}


// Recursive
Node* reverseLLRecursive(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* newhead = reverseLLRecursive(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newhead;

    // TC : O(n)
    // SC : O(n)  recursive stack space 
}


int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5, 6};
    Node* head = constructLL(arr1);

    printLinkedList(head);

    head = reverseLLRecursive(head);

    printLinkedList(head);
    return 0;
}
