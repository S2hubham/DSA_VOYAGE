#include <bits/stdc++.h>
using namespace std;


// seggregate odd even index nodes in LL

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


Node* odd_even(Node* head){
    // brute
    /* if(head == NULL || head->next == NULL) return head;
    Node* temp = head;
    vector<int> arr;
    // get all odd index nodes
    while(temp->next != NULL && temp->next->next != NULL){   //TC : O(n/2)
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    arr.push_back(temp->data);

    // get all even index nodes
    temp = head->next;
    while(temp->next != NULL && temp->next->next != NULL){  //TC : O(n/2)
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    arr.push_back(temp->data);

    // re-arrange LL 
    temp = head;
    int i = 0;
    while(temp != NULL){     //TC : O(n)
        temp->data = arr[i];
        temp = temp->next;
        i++;
    }
    return head; */

    // TC : O(N)
    // SC : O(n)


    // better
    if(head == NULL || head->next == NULL) return head;
    Node* odd = head;
    Node* even = head->next;
    Node* evenhead = head->next;
    // NOte : even is always ahead of odd hence check for even
    while(even != NULL && even->next != NULL){
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenhead;  
    return head;

    // TC : O(n)  Half the number of nodes in the list (since we process both odd and even nodes simultaneously)
    // SC : O(1)
}


int main()
{
    vector<int> arr1 = {1, 3, 4, 2, 5};
    Node* head = constructLL(arr1);

    printLinkedList(head);

    head = odd_even(head);

    printLinkedList(head);

    return 0;
}
