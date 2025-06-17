#include<bits/stdc++.h>
using namespace std;


// Identical Binary Tree
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


bool identical(Node* root1, Node* root2){
    if(root1 == NULL || root2 == NULL){
        return (root1 == root2);
    }

    return ((root1->data == root2->data) 
    && identical(root1->left, root2->left) 
    && identical(root1->right, root2->right));

    // TC : O(n)
    // SC : O(h) ~= O(n)

    
    /* 
    
    if any of the node is null 
        if both nodes are null return true -> base condition
        if one node is null and other is not then return false

    if both trees nodes data matches and both trees leftnode and rightnode are identical then retun true
    else false 

    */
}


int main(){
    // tree 1
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

    // tree 2
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->left->left = new Node(4); 
    root1->left->right = new Node(5); 
    root1->left->right->left = new Node(8); //missing this one

    root1->right = new Node(3);
    root1->right->left = new Node(6); 
    root1->right->right = new Node(7);
    root1->right->right->left = new Node(9);  
    root1->right->right->right = new Node(10); 

    cout << ((identical(root, root1)) ? "Trees are identical" : "Trees are not identical");

    return 0;
}