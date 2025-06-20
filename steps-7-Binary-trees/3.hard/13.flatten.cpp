#include<bits/stdc++.h>
using namespace std;


// flatten binary tree to linked list
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


void flatten(Node* root){
    if(!root)   return;

    flatten(root->right);
    flatten(root->left);

    if(root->left){
        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* curr = root->right;
        while(curr->right){
            curr = curr->right;
        }

        curr->right = temp;
    }

    // TC : O(n)
    // SC : O(h)
}


void preorder_traversal(Node* root){
    if(!root)   return;

    cout<< root->data <<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

int main(){
    /* Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);  
 
    root->right = new Node(3);
    root->right->left = new Node(8); 
    root->right->right = new Node(9); */ 
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
 
    root->right = new Node(3); 

    flatten(root);

    preorder_traversal(root);

    return 0;
}