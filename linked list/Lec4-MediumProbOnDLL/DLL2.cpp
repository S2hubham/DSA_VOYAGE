#include <iostream>
#include <vector>
#include<stack>
using namespace std;

// Find all pairs with given sum in DLL

class Node {
public:
    Node* back;
    int data;
    Node* next;

    Node(int data1) {
        this->back = NULL;
        this->data = data1;
        this->next = NULL;
    }

    Node(Node* back1, int data1, Node* next1) {
        // this ensure that actual value is passed and not the memory location
        this->back = back1;
        this->data = data1;
        this->next = next1;
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


void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


Node* getTail(Node* head){
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    return tail;
}

vector<pair<int, int>> Pairs_sum(Node* head, int sum){
    // brute
    /* vector<pair<int, int>> pairs;
    Node* temp1 = head;
    Node* temp2 = NULL;
    while(temp1 != NULL){
        temp2 = temp1->next;
        while(temp2 != NULL && ((temp1->data + temp2->data) <= sum)){
            int x = temp1->data;
            int y = temp2->data;
            if((x+y) == sum){
                pairs.push_back({x, y});
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return pairs; */

    // TC : O(n * (n-1)/2) ~ O(n^2)
    // SC O (2 * n)



    // better
    vector<pair<int, int>> pairs;  
    Node* left = head;
    Node* right = getTail(head);          // TC : O(n)
    while(left->data < right->data){      // TC : O(n)
        int x = left->data + right->data;
        
        if(x == sum){
            pairs.push_back({left->data, right->data});
            left = left->next;
            right = right->back;
        }
        else if(x < sum){
            left = left->next;
        }
        else{
            right = right->back;
        }
    }
    return pairs;

    // TC : O(2n)
    // SC : O(k) h = noumber of pairs
}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node* head = constructLL(arr);

    cout << "Pairs for give sum are:" << endl;

    vector<pair<int, int>> ans = Pairs_sum(head, 6);

    for(int i = 0; i < ans.size(); i++){
        cout<< "( " << ans[i].first << " , " << ans[i].second << " ) " <<endl;
    }

    return 0;
}