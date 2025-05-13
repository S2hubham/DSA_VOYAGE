#include<bits/stdc++.h>
using namespace std;


// Check for children sum property

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


bool isLeaf(Node* root){
    if(!root)   return true;
    if(root->left == NULL && root->right == NULL)   return true;
    else return false;
}


void childrenSum(Node* root){
    // base case
    if(!root || isLeaf(root))   return;

    int leftChildData = (root->left) ? root->left->data : 0;
    int rightChildData = (root->right) ? root->right->data : 0;

    if(root->data > leftChildData + rightChildData){
        if(root->left)  root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }
    else{
        root->data = leftChildData + rightChildData;
    }

    childrenSum(root->left);
    childrenSum(root->right);

    leftChildData = (root->left) ? root->left->data : 0;
    rightChildData = (root->right) ? root->right->data : 0;

    root->data = leftChildData + rightChildData;
}


void preorder(Node* root){
    if(!root)   return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}



int main(){
    /* Node* root = new Node(50);
    root->left = new Node(7);
    root->left->left = new Node(3); 
    root->left->left->left = new Node(5);

    root->right = new Node(2);
    root->right->right = new Node(1);  
    root->right->right->right = new Node(30);  */
    // 100 50 50 50 50 50 50 


    Node* root = new Node(50);
    root->left = new Node(7);
    root->left->left = new Node(3); 
    root->left->right = new Node(5);

    root->right = new Node(2);
    root->right->left = new Node(1);  
    root->right->right = new Node(30);
    // 200 100 50 50 100 50 50 
    
    childrenSum(root);
    preorder(root);
      
    return 0;
}


/* 

Top-Down Enforcement (Before Recursion):
    If a parent’s data is greater than the sum of its children, then push the parent's value down to the children (increase child values).
    This avoids violating the constraint when you later update the parent using children's values.
Bottom-Up Fix (After Recursion):
    After recursive calls, the children will already satisfy the children sum property, so you can safely set:
        root->data = left + right;

*/