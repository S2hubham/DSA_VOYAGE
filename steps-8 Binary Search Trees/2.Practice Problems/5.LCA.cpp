#include<bits/stdc++.h>
using namespace std;


// LCA in BST
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


Node* LCA(Node* root, Node* n1, Node* n2){
    if(!root)   return NULL;

    Node* curr = root;

    while(curr){
        if(curr->data == n1->data || curr->data == n2->data)    return curr;
        else if(curr->data > n1->data){
            if(curr->data > n2->data){
                curr = curr->left;
            }
            else{
                return curr;
            }
        }
        else if(curr->data < n1->data){
            if(curr->data < n2->data){
                curr = curr->right;
            }
            else{
                return curr;
            }
        }
    }

    return NULL;

    // TC : O(H)
    // SC : O(1)
}


int main() {
    Node* root = new Node(10);

    root->left = new Node(4);
    root->left->left = new Node(3); 
    root->left->right = new Node(8);
    root->left->left->left = new Node(1);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(9);
    root->left->left->left->right = new Node(2);
    root->left->right->left->left = new Node(5);
    root->left->right->left->right = new Node(7);

    root->right = new Node(13); 
    root->right->left = new Node(11);
    root->right->right = new Node(15);

    Node* n1 = root->left->left->left->right;
    Node* n2 = root->left->right->left->left;
    Node* ans = LCA(root, n1, n2);

    cout<<"LCA of given nodes is : "<<ans->data;

    return 0;
}
