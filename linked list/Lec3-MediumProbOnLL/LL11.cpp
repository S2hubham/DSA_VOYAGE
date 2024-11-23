#include <bits/stdc++.h>
using namespace std;

// sort a LL with 0s 1s and 2s

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

Node *find_middle(Node *head)
{ // TC : O(n/2) = O(n)
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *mergeTwoLL(Node *list1, Node *list2)
{ // TC : O(n)
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data < list2->data)
        {
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }
    if (list1)
    {
        temp->next = list1;
    }
    else
    {
        temp->next = list2;
    }
    return dummy->next;
}

Node *sort_LL(Node *head)
{
    // brute
    /* if(head == NULL) return head;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0){
            cnt0++;
        }
        else if(temp->data == 1){
            cnt1++;
        }
        else{
            cnt2++;
        }
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        if(cnt0){
            temp->data = 0;
            temp = temp->next;
            cnt0--;
        }
        else if(cnt1){
            temp->data = 1;
            temp= temp->next;
            cnt1--;
        }
        else{
            temp->data = 2;
            temp = temp->next;
            cnt2--;
        }
    }
    return head; */

    // TC : O(2n) = O(n)
    // SC : O(1)

    // better
    if(head == NULL || head->next == NULL) return head;
    Node *dummyzero = new Node(-1);
    Node *dummyone = new Node(-1);
    Node *dummytwo = new Node(-1);
    Node *zero = dummyzero;
    Node *one = dummyone;
    Node *two = dummytwo;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }

    zero->next = (dummyone->next) ? dummyone->next : dummytwo->next;
    one->next = dummytwo->next; 
    two->next = NULL;

    delete dummyzero;
    delete dummyone;
    delete dummytwo;

    return dummyzero->next;

    // TC : O(n)
    // SC : O(1)
}

int main()
{
    vector<int> arr1 = {0, 1, 2, 1, 1, 0, 2, 2};
    Node *head = constructLL(arr1);

    printLinkedList(head);

    head = sort_LL(head);

    cout << "sorted : \n";

    printLinkedList(head);

    return 0;
}
