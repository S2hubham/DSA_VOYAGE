#include<bits/stdc++.h>
using namespace std;


// Symmetric Binary Tree
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


bool func(Node* root1, Node* root2){
    // base case
    if(root1 == NULL || root2 == NULL){
        return root1 == root2;
    }

    if(root1->data != root2->data)  return false;

    return (func(root1->left, root2->right) && func(root1->right, root2->left));

    // TC : O(n)
    // SC : O(h) ~= O(n)
}


void symmetric(Node* root){
    if(func(root->left, root->right)){
        cout<<"Symmetric binary tree";
    }
    else{
        cout<<"Unsymmetric binary tree";
    }
} 


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    // root->left->left = new Node(3); 
    root->left->right = new Node(4);  
 

    root->right = new Node(2);
    root->right->left = new Node(3); 
    root->right->right = new Node(4); 

    symmetric(root);   
    return 0;
}