#include<bits/stdc++.h>
using namespace std;


// Search in BST
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


bool search(Node* root, Node* target){
    if(!root)   return false;

    Node* curr = root;
    while(curr){
        if(curr == target){
            return true;
        }
        else if(curr->data > target->data){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
    return false;

    // TC : O(log n) / O(n)  avg(balanced tree) / worst(skewed tree)
    // SC : O(1)
}


int main(){
    Node* root = new Node(8);
    root->left = new Node(5);
    root->left->left = new Node(4); 
    root->left->right = new Node(7); 
    root->left->right->left = new Node(6);
 
    root->right = new Node(12);
    root->right->left = new Node(10); 
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    Node* target1 = root->right->left;
    Node* target2 = new Node(100); 

    if(search(root, target1)){
        cout<<target1->data<<" is present in BST";
    }
    else{
        cout<<target1->data<<" is not present in BST";
    }

    return 0;
}