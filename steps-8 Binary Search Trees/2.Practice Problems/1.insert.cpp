#include<bits/stdc++.h>
using namespace std;


// Insert node in BST
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


Node* insert_rec(Node* root, int key){
    // base case
    if(!root)   return new Node(key);

    if(key > root->data){
        root->right = insert_rec(root->right, key);
    }
    else if(key < root->data){
        root->left = insert_rec(root->left, key);
    }

    return root;

    // TC : O(logn)
    // SC : O(logn)
}

Node* insert_itr(Node* root, int key){
    if(!root)   return new Node(key);

    Node* parent = NULL;
    Node* curr = root;

    /* while(curr){
        parent = curr;
        if(key < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
        curr = (key > curr->data) ? curr->right : curr->left;
    }

    if(parent->data > key){
        parent->left = new Node(key);
    }
    else{
        parent->right = new Node(key);
    } */

    // shorthand
    while(curr){
        parent = curr;
        curr = (key > curr->data) ? curr->right : curr->left;
    }
    Node*& link = (key < parent->data) ? parent->left : parent->right;
    link = new Node(key);


    return root;

    // TC : O(logn)
    // SC : O(1)
}


void preorder_traversal(Node* root){
    if(!root)   return;

    cout<< root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(3); 
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);
    root->left->right = new Node(6); 
    root->left->right->right = new Node(9);
 
    root->right = new Node(13);
    root->right->left = new Node(11); 
    root->right->right = new Node(14);

    cout<<"Before : ";
    preorder_traversal(root);

    int key = 8;
    // root = insert_rec(root, key);
    root = insert_itr(root, key);

    cout<<"\n\nAfter  : ";
    preorder_traversal(root);

    return 0;
}

// Before : 10 5 3 2 4 6 9 13 11 14 
// After  : 10 5 3 2 4 6 9 8 13 11 14 