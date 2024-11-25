#include <bits/stdc++.h>
using namespace std;

// Add 1 to the LL

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

Node *find_middle(Node *head)
{ // TC : O(n/2) = O(n)
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *reverseLL(Node *head)
{
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

int helper(Node* temp){
    if(temp == NULL){
        return 1;
    }
    int carry = helper(temp->next);
    temp->data += carry;
    if(temp->data < 10){
        return 0;
    }
    temp->data = 0;
    return 1;
}

Node *add_1(Node *head)
{
    /* if(head == NULL) return NULL;
    head = reverseLL(head);         // TC : O(n)
    int carry = 1;
    Node* temp = head;
    while(temp != NULL){            // TC : O(n)
        int x = temp->data;
        int sum = x + carry;
        int newdata = sum % 10;
        temp->data = newdata;
        carry = sum / 10;
        temp = temp->next;
    }

    head = reverseLL(head);         // TC : O(n)

    if(carry){
        Node* newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }
    return head; */

    // TC : O(3n) = O(n)
    // SC : O(1)


    // better
    int carry = helper(head);
    if(carry){
        Node* newhead = new Node(1);
        newhead->next = head;
        head =  newhead;
    }
    return head;

    // TC : O(n)
    // SC : O(n)   recursive stack space
}

int main()
{
    vector<int> arr1 = {9, 9, 9, 9};
    Node *head = constructLL(arr1);

    printLinkedList(head);

    head = add_1(head);

    printLinkedList(head);

    return 0;
}
