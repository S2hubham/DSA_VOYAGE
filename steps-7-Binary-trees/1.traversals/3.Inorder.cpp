#include<bits/stdc++.h>
using namespace std;


// In-Order traversal on Binary tree
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


void inorder_traversal(Node* node){
    // base case
    if(node == NULL)    return;

    // L-D-R
    inorder_traversal(node->left);
    cout<<node->data<<" ";
    inorder_traversal(node->right);

    // TC : O(n)
    // SC : O(auxilliary space height of tree)
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->left->right->left = new Node(8); 

    root->right = new Node(3);
    root->right->left = new Node(6); 
    root->right->right = new Node(7);
    root->right->right->left = new Node(9);  
    root->right->right->right = new Node(10); 

    inorder_traversal(root);
    
    return 0;
}