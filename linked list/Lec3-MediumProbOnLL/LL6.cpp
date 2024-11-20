#include <bits/stdc++.h>
using namespace std;


// Length of a loop in LL

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

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


Node* reverseLL(Node* head){
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        head = temp;
        temp = front;
    }
    return head;

    // TC : O(n)
    // SC : O(1)  
}


bool isPalindrome(Node* head){
    // brute (using stack)
    /* stack<int> st;
    Node* temp = head;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        if(temp->data != st.top()){
            return false;
        }
        temp = temp->next;
        st.pop();
    }
    return true; */

    // TC : O(n)
    // SC : O(n)


    // better
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){   // TC : O(n/2)
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* first = head;
    Node* newhead = reverseLL(slow->next);  // TC : O(n/2)
    Node* second = newhead;
    while(second != NULL){   // TC : O(n/2)
        if(first->data != second->data) return false;
        first = first->next;
        second = second->next;
    }
    newhead = reverseLL(newhead);  // TC : O(n/2)
    return true;

    // TC : O(N/2 + N/2 + N/2 + N/2), which simplifies to O(2N), ultimately representing O(N). 
    // SC : O(1)
}


int main()
{
    vector<int> arr1 = {1, 2, 3, 2, 1};
    Node* head = constructLL(arr1);

    if (isPalindrome(head)) {
        cout << "linked list is Palindrome." << endl;
    } else {
        cout << "linked list is not a Palindrome." << endl;
    }

    return 0;
}
