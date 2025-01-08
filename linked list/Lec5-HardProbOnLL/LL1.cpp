#include <iostream>
#include <vector>
using namespace std;


// Reverse Nodes in k groups in LL

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


Node* reverseLL(Node* head){
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


Node* reverse_k_groups(Node* head, int k){
    Node* temp = head;
    Node* kthNode = head;
    bool flag = false;
    for(int i = 1; i < k; i++){
        kthNode = kthNode->next;
        if(kthNode == NULL) break;
    }
    while(kthNode != NULL){
        Node* nextNode = kthNode->next;
        kthNode->next = NULL;
        Node* newHead = reverseLL(temp);    // O(n)
        Node* prevNode = temp;
        if(head == temp){
            head = kthNode;
        }
        if(nextNode == NULL){
            break;
        }
        temp = nextNode;
        kthNode = temp;
        for(int i = 1; i < k; i++){        // O(n)
            kthNode = kthNode->next;
            if(kthNode == NULL) break;
        }
        prevNode->next = (kthNode) ? kthNode : temp;
    }
    return head;

    // TC : O(2n)
    // SC : O(1)
}


int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* head = constructLL(arr1);

    printLinkedList(head);

    cout<<"\nAfter reversing k groups \n\n";

    head = reverse_k_groups(head, 3);

    printLinkedList(head);

    return 0;
}
