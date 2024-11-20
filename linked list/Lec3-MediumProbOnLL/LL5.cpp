#include <bits/stdc++.h>
using namespace std;


// Length of a loop in LL

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



int detectloop(Node* head){
    // brute
    /* unordered_map<Node*, int> mpp;
    Node* temp = head;
    int timer = 1;
    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()){
            int val = mpp[temp];
            return (timer-val);
        }
        mpp[temp] = timer;
        timer++;
        temp = temp->next;
    }
    return 0; */

    // TC : O(n)
    // SC : O(n)


    // better 
    Node* slow = head;
    Node* fast = head;
    bool flag = false;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            flag = true;
            break;
        }
    }
    int len = 0;
    if(flag == true){
        slow = slow->next;
        while(slow != fast){
            len++;
            slow = slow->next;
        }
    }
    return (len+1);

    // TC : O(n)
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

    cout << "Length of loop : " << detectloop(head);

    return 0;
}
