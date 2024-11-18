#include <iostream>
#include <vector>
using namespace std;


// Middle of LL  (works for both even/odd length LL)

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


Node* middle(Node* head){
    // brute
    /* Node* temp = head;
    int n = 0;
    while(temp != NULL){
        n++;
        temp = temp->next;
    }

    int idx = (n/2) + 1;

    temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == idx){
            break;
        }
        temp = temp->next;
    }
    return temp; */

    // TC : O(n + n/2)  first pass and second pass
    // SC : O(1)


    // better (tortise hare method)
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
    
    // TC : O(n)
    // SC : O(1)
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5, 6};
    Node* head = constructLL(arr1);

    printLinkedList(head);

    head = middle(head);
    cout<<"Data : "<<head->data;

    return 0;
}
