#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    // Default constructor
    Node() {
        data = "";
        next = NULL;
    }

    // Parameterized Constructor
    Node(string data) {
        // this ensure that actual value is passed and not the memory location
        this->data = data;
        this->next = NULL;
    }
};

class Solution {
public:
    Node* constructLL(vector<string>& arr) {
        // Create the head node with the first element in the array
        Node* head = new Node(arr[0]);
        Node* mover = head;

        // Create the remaining nodes
        for (int i = 1; i < arr.size(); i++) {
            Node* temp = new Node(arr[i]);
            mover->next = temp;  // Link the previous node to the new node
            mover = temp;       // Move the pointer to the new node
        }

        return head;
    }
};

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " | (" << temp->next << ") -> \n";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void printLength(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    cout<<"\nLength of LL is : "<<cnt<<endl;
}

void search(Node* head, string val){
    Node* temp = head;
    while(temp){
        if(temp->data == val){
            cout<<"\nPresent";
            return;
        }
        temp = temp->next;
    }
    cout<<"\nAbsent";
}

int main() {
    vector<string> arr = {"shubham", "suresh", "kokane"};
    Solution sol;
    Node* head = sol.constructLL(arr);

    // Print the constructed linked list
    printLinkedList(head);

    printLength(head);

    search(head, "shubham");

    return 0;
}
