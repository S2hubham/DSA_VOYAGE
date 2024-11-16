#include <iostream>
#include <vector>
using namespace std;

// deletion logic build

class Node {
public:
    string data;
    Node* next;

    Node() {
        data = "";
        next = NULL;
    }

    Node(string data) {
        // this ensure that actual value is passed and not the memory location
        this->data = data;
        this->next = NULL;
    }
};

class Solution {
public:
    Node* constructLL(vector<string>& arr) {
        Node* head = new Node(arr[0]);
        Node* mover = head;

        // Create the remaining nodes
        for (int i = 1; i < arr.size(); i++) {
            Node* temp = new Node(arr[i]);
            mover->next = temp; 
            mover = temp;      
        }

        return head;
    }
};

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


Node* deleteHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}


Node* deleteTail(Node* head){
    if(head -> next == NULL || head == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete (temp->next);
    temp->next = NULL;
    return head;
}


Node* deleteK(Node* head, int k){
    // case 1 : when LL is empty
    if(head == NULL) return head;

    // case 2 : when we want to delete head 
    if(k == 1){
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }

    // case 3 : want to delete last element or any element
    Node* temp = head;
    Node* prev = NULL;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev -> next = prev -> next -> next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;

    // TC : O(k)
}

Node* valueBasedDeletion(Node* head, string s){
    // case 1 : when LL is empty
    if(head == NULL) return head;

    // case 2 : when we want to delete head 
    if(head->data == s){
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }

    // case 3 : want to delete last element or any element
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        if(temp->data == s){
            prev -> next = prev -> next -> next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;

    // TC : O(k)
}

int main() {
    vector<string> arr = {"shubham", "suresh", "kokane"};
    Solution sol;
    Node* head = sol.constructLL(arr);

    printLinkedList(head);

    // head = deleteHead(head);

    // head = deleteTail(head);

    // head = deletK(head, 2);

    head = valueBasedDeletion(head, "shubham");

    printLinkedList(head);

    return 0;
}
