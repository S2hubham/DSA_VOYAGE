#include <iostream>
#include <vector>
#include<stack>
using namespace std;

// Delete redundant elements

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
    cout<<"NULL <-> ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


Node* del_redundant(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* temp = head->next;
    Node* rear = head;
    while(temp != NULL){
        Node* front = temp->next;
        if(rear->data == temp->data){
            temp->next = temp->back = NULL;
            rear->next = front;
            if(front) front->back = rear;
            delete temp;
            temp = front;
        }
        else{
            rear = temp;
            temp = temp->next;
        }
    }
    return head;

    // TC : O(n)
    // SC : O(1)


    /* if(head == NULL || head->next == NULL) return head;
    Node* temp = head;
    while(temp != NULL && temp->next != NULL){
        Node* nextNode = temp->next;
        while(nextNode != NULL && nextNode->data == temp->data){
            Node* duplicate = nextNode;
            nextNode = nextNode->next;
            duplicate->next = duplicate->back = NULL;
            delete duplicate;
        }
        temp->next = nextNode;
        if(nextNode) nextNode->back = temp;
        temp = temp->next;
    }
    return head; */

    // TC : O(n)
    // SC : O(1)
}


int main() {
    vector<int> arr = {1, 1, 2, 2, 3};
    Node* head = constructLL(arr);

    printLinkedList(head);

    cout << "\nAfter removing redundant elements in LL : \n" << endl;

    head = del_redundant(head);

    printLinkedList(head);

    return 0;
}