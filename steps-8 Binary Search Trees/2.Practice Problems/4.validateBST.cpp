#include<bits/stdc++.h>
using namespace std;


// Validate a BST
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


bool validate(Node* root, long L_range, long R_range){
    if(!root)   return true;
    if(root->data <= L_range || root->data >= R_range)    return false;

    return (validate(root->left, L_range, root->data) && validate(root->right, root->data, R_range));
}


int main() {
    Node* root = new Node(13);
    root->left = new Node(10);
    root->left->left = new Node(7); 
    root->left->right = new Node(12);
    root->left->left->right = new Node(9);
    root->left->left->right->left = new Node(8);

    root->right = new Node(15); 
    root->right->left = new Node(14);
    root->right->right = new Node(17);
    root->right->right->left = new Node(16);

    cout<<((validate(root, LONG_MIN, LONG_MAX)) ? "It is BST" : "It is not a BST");

    return 0;
}
