#include <bits/stdc++.h>
using namespace std;


// remove nth node from end in LL

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


Node* remove_nth(Node* head, int x){
    // brute
    /* if(head == NULL) return head;
    Node* temp = head;
    int n = 0;
    while(temp != NULL){   // TC : O(n)
        n++;
        temp = temp->next;
    }
    int cnt = n;
    temp = head;
    Node* prev = NULL;
    while(temp != NULL){   // TC : O(x)
        if(cnt == x){
            Node* front = temp->next;
            if(prev){
                prev->next = front;
            }
            else{
                head = temp->next;
            }
            temp->next = NULL;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
        cnt--;
    }
    return head; */

    // TC : O(2n) : O(n)  when x == n
    // SC : O(1)


    // better
    Node* fast = head;
    Node* slow = head;
    for(int i = 0; i < x; i++){
        fast = fast->next;
    }
    if(fast == NULL){
        head = head->next;
        slow->next = NULL;
        delete slow;
        return head;
    }

    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }

    Node* delnode = slow->next;
    slow->next = slow->next->next;
    delnode->next = NULL;
    delete delnode;
    return head;

    // TC : O(n)  fast pointer is moving only till the end of LL
    // SC : O(1)
}


int main()
{
    vector<int> arr1 = {1, 3, 4, 2, 5};
    Node* head = constructLL(arr1);

    printLinkedList(head);

    head = remove_nth(head, 5);

    printLinkedList(head);

    return 0;
}
