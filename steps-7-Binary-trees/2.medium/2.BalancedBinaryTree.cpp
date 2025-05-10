#include<bits/stdc++.h>
using namespace std;


// Balanced Binary Tree
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


int balanced(Node* root){
    // base case
    if(root == NULL){
        return 0;
    }

    int l = balanced(root->left);
    if(l == -1)   return -1;
    int r = balanced(root->right);
    if(r == -1)   return -1;

    // check for balance
    if(abs(l - r) > 1)   return -1;

    return (1 + max(l, r));
}


int main(){
    /* Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->left->right->left = new Node(8); 

    root->right = new Node(3);
    root->right->left = new Node(6); 
    root->right->right = new Node(7);
    root->right->right->left = new Node(9);  
    root->right->right->right = new Node(10);  */


    Node* root = new Node(3);
    root->left = new Node(9);

    root->right = new Node(20);
    root->right->left = new Node(4); 
    root->right->right = new Node(5);

    int ans = balanced(root);

    cout << ((ans != -1) ? "Tree is balanced" : "Tree is not balanced");

    return 0;
}