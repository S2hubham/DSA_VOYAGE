#include <iostream>
#include <vector>
using namespace std;

// Reverse a DLL

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


// Function to reverse a doubly linked list
Node* reverseDLL(Node* head) {
    if (head == nullptr) return nullptr;
    Node* temp = head;
    Node* newHead = nullptr;

    while (temp != nullptr) {
        // Swap next and prev pointers
        Node* front = temp->next;
        temp->next = temp->back;
        temp->back = front;
        
        // Move the newHead pointer to the current node
        newHead = temp;
        
        // Move temp to the next node (previously next node)
        temp = front;
    }
    cout<<"After reversal : \n";
    return newHead;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 6};
    Node *head = constructLL(arr);

    printLinkedList(head);

    head = reverseDLL(head);

    printLinkedList(head);

    return 0;
}
