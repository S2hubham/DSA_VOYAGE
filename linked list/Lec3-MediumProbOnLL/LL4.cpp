#include <bits/stdc++.h>
using namespace std;


// Starting of a loop in LL

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        // this ensure that actual value is passed and not the memory location
        this->data = data;
        this->next = NULL;
    }
};

Node *constructLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp; 
        mover = temp;       
    }

    return head;
}


void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}



Node* detectloop(Node* head){
    // brute
    /* unordered_map<Node*, int> mpp;
    Node* temp = head;
    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()){
            return temp;
        }
        mpp[temp] = 1;
        temp = temp->next;
    }
    return NULL; */

    // TC : O(n) only for traversal and not the insertion/fetching of data in unordered map
    // SC : O(n)


    // better (slow fast)
    Node* slow = head;
    Node* fast = head;
    bool flag = false;
    // step 1 : check if loop exists
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            flag = true;
            break;
        }
    } 
    // step 2 : find start node of loop
    if(flag == true){
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    return NULL;

    // TC : O(n)  might be this as we dont know where fast will meet slow 
    // SC : O(1)
}


int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    node1-> next = node2;
    Node* node3 = new Node(3);
    node2-> next = node3;
    Node* node4 = new Node(4);
    node3->next = node4;
    Node* node5 = new Node(5);
    node4-> next = node5;

    // Make a loop from node5 to node2
    node5->next = node2;

    Node* head = node1;

    Node* start = detectloop(head);

    if (start != NULL) {
        cout << "Loop detected in the LL \nstarting node is :  "<< start->data << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }
    return 0;
}
