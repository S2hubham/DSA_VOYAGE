#include<bits/stdc++.h>
using namespace std;


// Post-Order traversal on Binary tree
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


void postorder_traversal(Node* node){
    // base case
    if(node == NULL)    return;

    // L-R-D
    postorder_traversal(node->left);
    postorder_traversal(node->right);
    cout<<node->data<<" ";

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

    postorder_traversal(root);
    
    return 0;
}