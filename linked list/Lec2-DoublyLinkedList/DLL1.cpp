#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    Node *back;
    int data;
    Node *next;

    Node(int data)
    {
        // this ensure that actual value is passed and not the memory location
        this->back = NULL;
        this->data = data;
        this->next = NULL;
    }

    Node(Node *back1, int data, Node *next)
    {
        this->back = back1;
        this->data = data;
        this->next = next;
    }
};

Node *constructLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(prev, arr[i], NULL);
        prev->next = temp; 
        prev = temp;       
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


void printLength(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    cout << "\nLength of LL is : " << cnt << endl;
}


void search(Node *head, int val)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == val)
        {
            cout << "\nPresent";
            return;
        }
        temp = temp->next;
    }
    cout << "\nAbsent";
}


int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = constructLL(arr);

    printLinkedList(head);

    printLength(head);

    search(head, 5);

    return 0;
}
