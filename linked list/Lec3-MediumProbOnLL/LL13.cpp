#include <bits/stdc++.h>
using namespace std;

// Find intersection of two LL

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

int getdiff(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    int len1 = 0, len2 = 0;
    while(temp1 != NULL || temp2 != NULL){     // TC : O(n1 + n2)
        if(temp1 != NULL){
            len1++;
            temp1 = temp1->next;
        }
        if(temp2 != NULL){
            len2++;
            temp2 = temp2->next;
        }
    }
    return (len1 - len2);
}

Node *intersection(Node *head1, Node *head2)
{
    // brute
    /* unordered_set<Node*> st;
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1 != NULL){                 // TC : O(n1)
        st.insert(temp1);
        temp1 = temp1->next; 
    }
    while(temp2 != NULL){                 // TC : O(n2)
        if(st.find(temp2) != st.end()){
            return temp2;
        }
        temp2 = temp2->next;
    }
    return NULL; */

    // TC : O(n1 + n2) = O(n)
    // SC : O(n1)   

    


    // better
    /* Node* temp1 = head1;
    Node* temp2 = head2;
    int diff = getdiff(head1, head2);
    if(diff > 0){                // TC : O(n1 - n2)
        while(diff != 0){
            temp1 = temp1->next;
            diff--;
        }
    }
    else{                        // TC : O(n2 - n1)
        while(diff != 0){
            temp2 = temp2->next;
            diff++;
        }
    }

    // TC : O(n2) shorter length
    while(temp1 != NULL && temp2 != NULL){
        if(temp1 == temp2){
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return NULL; */

    // TC : O(2*n1 + n2) if n1 is bigger
    // TC : O(n1 + 2*n2) if n2 is bigger
    // SC : O(1)


    // OR 

    /* Node* temp1 = head1;
    Node* temp2 = head2;
    int n1 = 0, n2 = 0;
    while(temp1 != NULL){                 // TC : O(n1)
        n1++;
        temp1 = temp1->next;
    }
    while(temp2 != NULL){                 // TC : O(n2)
        n2++;
        temp2 = temp2->next;
    }

    int diff = 0;
    temp1 = head1;
    temp2 = head2;
    if(n2 > n1){
        diff = n2-n1;
        while(diff){
            temp2 = temp2->next;
            diff--;
        }
    }
    else{
        diff = n1-n2;
        while(diff){
            temp1 = temp1->next;
            diff--;
        }
    }
    cout<<"up"<<endl;

    while(temp1 != NULL && temp2 != NULL){        //TC : O(mod(n1-n2))
        if(temp1 == temp2){
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    cout<<"down"<<endl;
    return NULL; */

    // TC : O(n1 + n2 + mod(n1-n2))
    // SC : O(1)




    // best
    if(head1 == NULL || head2 == NULL) return NULL;
    Node* temp1 = head1;
    Node* temp2 = head2;
    // campare temp1 and temp2 boz that is base case when it is the same LL
    while(temp1 != temp2){
        if(temp1 == temp2){
            return temp1;
        }
        // transfer to other when it reaches its LL's end 
        temp1 = (temp1 != NULL) ? temp1->next : head2;
        temp2 = (temp2 != NULL) ? temp2->next : head1;
    }
    return temp1;

    // TC : O(n1+n2)
    // SC : O(1)
}

int main() {
    cout<<"hi";
    Node* head1 = new Node(1);
    Node* node12 = new Node(2);
    head1->next = node12;
    Node *node13 = new Node(3);
    node12->next = node13;

    Node* head2 = new Node(67);
    Node* node22 = new Node(6);
    head2->next = node22;

    // common part
    Node* common = new Node(8);
    common->next = new Node(9);
    common->next->next = new Node(10);

    node13->next = common;
    node22->next = common;


    // Find intersection
    Node* intersect = intersection(head1, head2);
    if (intersect) {
        cout << "Intersection Point: " << intersect->data << endl;
    } else {
        cout << "No Intersection Point" << endl;
    }

    return 0;
}

