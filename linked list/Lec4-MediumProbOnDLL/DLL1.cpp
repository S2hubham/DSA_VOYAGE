#include <iostream>
#include <vector>
#include<stack>
using namespace std;

// Delete all occurrences of a key in DLL

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


void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


Node* delAllOccOfKey(Node* head, int key){
    if(head == NULL) return NULL;
    Node* temp = head;
    Node* rear = NULL;
    Node* front = NULL;
    Node* delNode = NULL;
    while(temp != NULL){
        if(temp->data == key){
            delNode = temp;

            // case 1 : head
            if(temp == head){
                head = head->next;
                if(head != NULL) head->back = NULL;
            }
            // case 2 : middle or tail
            else{
                rear = temp->back;
                front = temp->next;
                if(rear) rear->next = front;
                if(front) front->back = rear;
            }

            temp = temp->next;
            delete delNode;
        }
        else{
            temp = temp->next;
        }
    }
    return head;

    // TC : O(n)
    // SC L O(1)
}


int main() {
    vector<int> arr = {5, 1, 2, 5, 3, 4, 5, 6, 5};
    Node* head = constructLL(arr);

    cout << "Original List:" << endl;
    printLinkedList(head);

    head = delAllOccOfKey(head, 5);

    cout << "List After Deletion:" << endl;
    printLinkedList(head);

    return 0;
}