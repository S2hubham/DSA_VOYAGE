#include <iostream>
#include <vector>
using namespace std;

// Insertion logic build

class Node {
public:
    Node* back;
    int data;
    Node* next;

    Node(int data1) {
        this->back = NULL;
        this->data = data1;
        this->next = NULL;
    }

    Node(Node* back1, int data1, Node* next1) {
        // this ensure that actual value is passed and not the memory location
        this->back = back1;
        this->data = data1;
        this->next = next1;
    }
};


Node *constructLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(prev, arr[i], NULL);
        prev->next = temp; 
        prev = temp;       
    }

    return head;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


Node* insertBeforeHead(Node* head, int x){
    if(head == NULL){
        return new Node(x);
    }

    Node* newNode = new Node(NULL, x, head);
    head->back = newNode;
    head = head->back;
    return head;
}


Node* insertBeforeTail(Node* head, int x){
    if(head == NULL){
        return new Node(x);
    }
    if(head->next == NULL){
        Node* newNode = new Node(NULL, x, head);
        head->back = newNode;
        head = head->back;
        return head;
    }
    
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(prev, x, temp);
    temp->back = prev->next = newNode;
    return head;
}


Node* insertBeforeKth(Node* head, int k, int val) {
    if(head == NULL) return new Node(val);

    Node* front = head;
    int cnt = 0;
    // Find the k-th node
    while (front != NULL) {
        cnt++;
        if(cnt == k) break;
        front = front->next;
    }

    Node* rear = front->back;

    // Case 1: inserting before head
    if (rear == NULL) {
        if(k != 1){
            cout<<"Wrong location for deletion\n";
        }
        return insertBeforeHead(head, val);
    }
    // Case 3: Inserting before tail or anywhere bewteen
    else {
        Node* newNode = new Node(rear, val, front);
        rear->next = newNode;
        front->back = newNode;
    }
    return head;
}


void insertBeforeNode(Node* node, int val){
    Node* rear = node->back;
    Node* newNode = new Node(rear, val, node);
    rear->next = newNode;
    node->back = newNode;
}


int main() {
    vector<int> arr = {1, 2, 3, 4, 6};
    Node *head = constructLL(arr);

    printLinkedList(head);

    // head = insertBeforeHead(head, 0);

    // head = insertBeforeTail(head, 5);

    // head = insertBeforeKth(head, 5, 100);

    // insertBeforeNode(head->next->next, 999);

    // deleteNode(head->next);

    printLinkedList(head);

    return 0;
}
