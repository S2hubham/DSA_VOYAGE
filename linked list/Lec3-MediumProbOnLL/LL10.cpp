#include <bits/stdc++.h>
using namespace std;


// sort a LL

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


Node* find_middle(Node* head){    // TC : O(n/2) = O(n)
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


Node* mergeTwoLL(Node* list1, Node* list2){   // TC : O(n)
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            temp->next = list1;
            temp = list1;
            list1 = list1->next; 
        }
        else{
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }
    if(list1){
        temp->next = list1;
    }
    else{
        temp->next = list2;
    }
    return dummy->next;
}


Node* sort_LL(Node* head){
    // brute 
    /* vector<int> arr;
    Node* temp = head;
    while(temp != NULL){             // TC : O(n)
        arr.push_back(temp->data);
        temp = temp->next;
    }
    sort(arr.begin(), arr.end());    //TC : O(n log n)
    temp = head;
    int i = 0;
    while(temp != NULL){             //TC : O(n)
        temp->data = arr[i];
        temp = temp->next;
        i++;
    }
    return head; */

    // TC : O(nlogn)
    // SC : O(n)


    // better (in terms of SC)
    if(head == NULL || head->next == NULL) return head;

    Node* middle = find_middle(head);   // TC : O(nlogn)
    Node* left = head;
    Node* right = middle->next;
    middle->next = NULL;

    left = sort_LL(left);
    right = sort_LL(right);
    return mergeTwoLL(left, right);     // TC : O(nlogn)

    // TC : O(nlogn)
    // SC : O(logn)  recursive stack space
}


int main()
{
    vector<int> arr1 = {6, 5, 3, 4, 2, 1};
    Node* head = constructLL(arr1);

    printLinkedList(head);

    head = sort_LL(head);

    cout<<"sorted : \n";

    printLinkedList(head);

    return 0;
}
