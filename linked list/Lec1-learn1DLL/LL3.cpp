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

    Node(string data, Node* nextNode) { // New constructor
        this->data = data;
        this->next = nextNode;
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


Node* insertHead(Node* head, string h){
    /* if(head == NULL){
        Node* newHead = new Node(h); 
    }
    Node* temp = new Node(h);
    temp->next = head; 
    return temp; */

    // OR

    Node* temp = new Node(h, head);
    return temp;

    // TC : O(1)
}


Node* insertTail(Node* head, string t){
    if(head == NULL){
        Node* temp = new Node(t, head);
        return temp;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp -> next;
    }
    Node* newlast = new Node(t, NULL);
    temp->next = newlast;
    return head;
}


Node* insertK(Node* head, string s,int k){
    // case 1 : when LL is empty && k == 1
    if(head == NULL){
        if(k == 1){
            return (new Node(s, NULL));
        }
        else{
            cout<<"Wtong Position as LL is empty";
            return head;
        }
    } 

    // case 2 : when we want to insert at head 
    if(k == 1){
        Node* temp = new Node(s, head);
        head = temp;
        return head;
    }

    // case 3 : want to insert at last position or kth position
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k-1){
            Node* newNode = new Node(s, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp -> next;
    }
    return head;

    // TC : O(k)
}


Node* valueBasedInsertion(Node* head, string newx, string oldx){
    // case 1 : when LL is empty
    if(head == NULL) return NULL;

    // case 2 : when we want to insert before head as value(oldx) is found at head 
    if(head->data == oldx){
        Node* newNode = new Node(newx, head);
        head = newNode;
        return head;
    }

    // case 3 : want to insert at last position or any position
    Node* temp = head;
    bool flag = false;
    while(temp != NULL){
        if((temp->next)->data == oldx){
            Node* newNode = new Node(newx, temp->next);
            temp->next = newNode;
            flag = true;
            break;
        }
        temp = temp -> next;
    }
    if(flag != true){
        cout<<"No such value present in LL"<<endl;
    }
    return head;

    // TC : O(k)
}

int main() {
    vector<string> arr = {"shubham", "suresh", "kokane"};
    Solution sol;
    Node* head = sol.constructLL(arr);

    printLinkedList(head);

    // head = insertHead(head, "Mr");

    // head = insertTail(head, "!");

    // head = insertK(head, "suiiii", 4);

    head = valueBasedInsertion(head, "suii", "kokane");

    printLinkedList(head);

    return 0;
}
