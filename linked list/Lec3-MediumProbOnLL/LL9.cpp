#include <bits/stdc++.h>
using namespace std;


// remove nth node from end in LL

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


Node* remove_middle(Node* head){
    // brute force
    /* if(head == NULL) return head;
    Node* temp = head;
    int n = 0;
    while(temp != NULL){    //TC : O(n)
        n++;
        temp = temp->next;
    }
    int mnode = (n/2);
    temp = head;
    n = 0;
    while(temp != NULL){    //TC : O(n/2)
        n++;
        if(mnode == n){
            Node* delNode = temp->next;
            temp->next = delNode->next;
            delNode->next = NULL;
            delete delNode;
            break;
        }
        temp = temp->next;
    }
    return head; */

    // TC : O(n + n/2) : O(n)
    // SC : O(1)


    // better
    if(head == NULL || head->next) return NULL;
    Node* slow = head;
    Node* fast = head;
    fast = fast->next->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* delNode = slow->next;
    slow->next = delNode->next;
    delNode->next = NULL;
    delete delNode;
    return head;

    // TC : O(n)   reduced from n+n/2 to n(single pass)
    // SC : O(1)
}


int main()
{
    vector<int> arr1 = {1, 3, 4, 2, 5, 6};
    Node* head = constructLL(arr1);

    printLinkedList(head);

    head = remove_middle(head);

    printLinkedList(head);

    return 0;
}
