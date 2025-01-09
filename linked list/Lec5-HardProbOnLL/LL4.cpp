#include <bits/stdc++.h>
using namespace std;


// Clone a LL with a next and random pointers

class Node {
public:
    Node* random;
    int data;
    Node* next;

    Node(int data1) {
        this->random = NULL;
        this->data = data1;
        this->next = NULL;
    }

    Node(Node* random1, int data1, Node* next1) {
        // this ensure that actual value is passed and not the memory location
        this->random = random1;
        this->data = data1;
        this->next = next1;
    }
};


void printLL(Node* head) {
    while (head != nullptr) {
        cout << "Data: " << head->data;
        if (head->random != nullptr) {
            cout << ", Random: " << head->random->data;
        } else {
            cout << ", Random: nullptr";
        }
        cout << endl;
        // Move to the next node
        head = head->next;
    }
}


Node* clone_LL(Node* head) {
    // brute
   /*  Node* temp = head;
    map<Node*, Node*> mpp;
    while(temp != NULL){
        Node* newNode = new Node(temp->data);
        mpp[temp] = newNode;
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL){
        Node* copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->random = mpp[temp->random];
        temp = temp->next;
    }

    return mpp[head]; */

    // TC : O(2n)
    // SC : O(n) + O(n)



    // Better
    Node* temp = head;

    // step 1 : Insert copynodes in between   // TC : O(n)
    while(temp != NULL){
        Node * copyNode = new Node(temp->data);
        copyNode->next = temp->next;
        temp->next = copyNode;
        temp = copyNode->next;
    } 

    // step 2 : Connect random pointers       // TC : O(n)
    temp = head;
    while(temp != NULL){
        Node* copyNode = temp->next;
        copyNode->random = (temp->random) ? temp->random->next : temp->random;
        temp = copyNode->next;
    }

    // step 3 : Connect next pointers       // TC : O(n)
    temp = head;
    Node* dummy = new Node(-1);
    Node* res = dummy;
    while(temp != NULL){
        res->next = temp->next;
        res = res->next;
        temp->next = res->next;
        temp = temp->next;
    }

    return (dummy->next);

    // TC : O(3n)
    // SC : O(1) 
}


int main() {
    Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    // Assigning random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    cout << "Original Linked List with Random Pointers:" << endl;
    printLL(head);

    Node* clonedList = clone_LL(head);

    cout << "\nCloned Linked List with Random Pointers:" << endl;
    printLL(clonedList);

    return 0;
}