#include <iostream>
#include <vector>
using namespace std;

// deletion logic build

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


Node* deleteHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    head->back = NULL;
    temp->next = NULL;
    delete temp;
    return head;
}


Node* deleteTail(Node* head){
    if(head -> next == NULL || head == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    Node* tail = temp->next;
    tail->back = NULL;
    delete (tail);
    temp->next = NULL;
    return head;
}


Node* deleteK(Node* head, int k) {
    if(head == NULL) return head;

    Node* temp = head;
    int cnt = 0;
    // Find the k-th node
    while (temp != NULL) {
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }

    Node* rear = temp->back;
    Node* front = temp->next;

    // Case 1: Deleting the head node
    if (rear == NULL) {
        if(k != 1){
            cout<<"Wrong location for deletion\n";
        }
        return deleteHead(head);
    }
    // Case 2: Deleting the tail node
    else if (front == NULL) {
        return deleteTail(head);
    }
    // Case 3: Deleting a middle node
    else {
        rear->next = front;
        front->back = rear;
        temp->next = NULL;
        temp->back = NULL;  
        delete temp;
    }
    return head;
}

// give node in not head as mentioned
void deleteNode(Node* temp){
    Node* front = temp->next;
    Node* rear = temp->back;
    if(front == NULL){
        rear->next = NULL;
        temp->back = NULL;
        delete temp;
    }

    front->back = rear;
    rear->next = front;
    temp->next = temp->back = NULL;
    delete temp;
    return;
}


Node* valueBasedDeletion(Node* head, int x){
    // case 1 : when LL is empty
    if(head == NULL) return head;

    // case 2 : when we want to delete head 
    if(head->data == x){
        Node* temp = head;
        head = head -> next;
        head->back = NULL;
        temp->next = NULL;
        delete temp;
        return head;
    }

    // case 3 : want to delete last element or any element
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        if(temp->data == x){
            break;
        }
        temp = temp -> next;
    }

    Node* rear = temp->back;
    Node* front = temp->next;

    // Case 1: Deleting the head node
    if (rear == NULL) {
        return deleteHead(head);
    }
    // Case 2: Deleting the tail node
    else if (front == NULL) {
        return deleteTail(head);
    }
    // Case 3: Deleting a middle node
    else {
        rear->next = front;
        front->back = rear;
        temp->next = NULL;
        temp->back = NULL;  
        delete temp;
    }
    return head;

    // TC : O(k)
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = constructLL(arr);

    printLinkedList(head);

    // head = deleteHead(head);

    // head = deleteTail(head);l

    // head = deleteK(head, 2);

    // deleteNode(head->next);

    head = valueBasedDeletion(head, 3);

    printLinkedList(head);

    return 0;
}
