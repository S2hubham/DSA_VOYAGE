#include <iostream>
#include <vector>
using namespace std;


// Addition of two LL 

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


Node* reversalAddition(Node* head1, Node* head2){
    Node* dummy = new Node(-1);
    Node* current = dummy;

    Node* temp1 = head1;
    Node* temp2 = head2;
    int a1 = 0, a2 = 0, c = 0;
    
    while(temp1 != NULL || temp2 != NULL){
        a1 = (temp1 == NULL) ? 0 : temp1->data;

        a2 = (temp2 == NULL) ? 0 : temp2->data;

        int sum = a1 + a2 + c;
        int add = sum % 10;

        Node* newNode = new Node(add);

        current->next = newNode;
        current = current->next;
        
        if(sum >= 10){
            c = sum / 10;
        }
        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next; 

    }
    if(c != 0){
        Node* newNode = new Node(c);
        current->next = newNode;
        current = current->next;
    }
    return dummy->next;

    // TC : O(max (n1, n2))
    // SC : O(max (n1, n2))
}


int main()
{
    vector<int> arr1 = {3, 5};
    Node* head1 = constructLL(arr1);
    vector<int> arr2 = {4, 5, 9, 9};
    Node* head2 = constructLL(arr2);

    printLinkedList(head1);
    printLinkedList(head2);

    Node* head = reversalAddition(head1, head2);

    printLinkedList(head);

    return 0;
}
