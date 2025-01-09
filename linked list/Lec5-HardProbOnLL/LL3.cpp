#include <bits/stdc++.h>
using namespace std;


// Flattening a LL

class Node {
public:
    Node* child;
    int data;
    Node* next;

    Node(int data1) {
        this->child = NULL;
        this->data = data1;
        this->next = NULL;
    }

    Node(Node* child1, int data1, Node* next1) {
        // this ensure that actual value is passed and not the memory location
        this->child = child1;
        this->data = data1;
        this->next = next1;
    }
};


void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->child;
    }
    cout << "NULL" << endl;
}


void printMultiLevelLinkedList(Node* head, int level = 0) {
    Node* temp1 = head;
    while(temp1 != NULL){
        Node* temp2 = temp1;
        while(temp2 != NULL){
            cout<<temp2->data;
            temp2 = temp2->child;
            cout<<"  ->  ";
        }
        cout<<"NULL"<<endl;
        temp1 = temp1->next;
    }
    cout<<"NULL";
}


Node* merge(Node* list1, Node* list2){
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            temp->child = list1;
            list1 = list1->child;
        }
        else{
            temp->child = list2;
            list2 = list2->child;
        }
        temp = temp->child;
        temp->next = NULL;
    }
    if(list1) temp->child = list1;
    else temp->child = list2;

    if(dummy->child) dummy->child->next = NULL;

    return dummy->child;
}


Node* flatten_LL(Node* head) {
    // (n = next length , m = child length)

    // brute
    /* Node* temp1 = head;
    vector<int> arr;

    while(temp1 != NULL){
        Node* temp2 = temp1;
        while(temp2 != NULL){
            arr.push_back(temp2->data);
            temp2 = temp2->child;
        }
        temp1 = temp1->next;
    }

    sort(arr.begin(), arr.end());

    head = new Node(arr[0]);
    temp1 = head;
    for(int i = 1; i < arr.size(); i++){
        Node* newNode = new Node(arr[i]);
        temp1->next = newNode;
        temp1 = temp1->next;
    }

    return head; */

    // TC : O( 2x + xlogx )    
    // SC : O(2x)
    // x = n*m   



    // better
    // base case
    if(head == NULL || head->next == NULL) return head;
    Node* mergedHead = flatten_LL(head->next);
    return merge(head, mergedHead);

    // TC : O(2 n*m)
    // SC : O(n)
}


int main() {
    Node* head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);

    head->child = new Node(7);
    head->child->child = new Node(8);
    head->child->child->child = new Node(30);

    head->next->child = new Node(20);

    head->next->next->child = new Node(22);
    head->next->next->child->child = new Node(50);

    head->next->next->next->child = new Node(35);
    head->next->next->next->child->child = new Node(40);
    head->next->next->next->child->child->child = new Node(45);

    // printMultiLevelLinkedList(head);

    Node* flattenedList = flatten_LL(head);

    printLinkedList(flattenedList);

    return 0;
}