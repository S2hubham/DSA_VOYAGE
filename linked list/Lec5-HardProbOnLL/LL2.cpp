#include <iostream>
#include <vector>
using namespace std;


// Rotate a LL

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


Node* rotateLL(Node* head, int k) {
    // Edge case 1: Empty list or single node
    if (head == NULL || head->next == NULL || k == 0) return head;

    Node* last = head;
    int n = 1; 
    while (last->next != NULL) {       // TC : O(n)
        last = last->next;
        n++;
    }

    k = k % n;

    // Edge case 2: If k is 0 after modulo, return the original head
    if (k == 0) return head;

    int x = n - k;
    Node* mover = head;
    for(int i = 1; i < x; i++){      // TC : O(n - k)
        mover = mover->next;
    }
    Node* newhead = mover->next;
    mover->next = NULL;
    last->next = head;

    return newhead;

    // TC : O(n)
    // SC : O(1)
}


int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5};
    Node* head = constructLL(arr1);

    printLinkedList(head);

    cout<<"\nAfter reversing k groups \n\n";

    head = rotateLL(head, 7);

    printLinkedList(head);

    return 0;
}
