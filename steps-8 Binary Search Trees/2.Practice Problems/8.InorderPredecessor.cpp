#include<bits/stdc++.h>
using namespace std;


// Inorder predecessor in BST
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


int in_pred(Node* root, Node* target){
    int pred = -1;
    Node* curr = root;
    while(curr){
        if(curr->data < target->data){
            pred = curr->data;
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    return pred;
}



int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(9);
    root->left->left->left = new Node(1);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(10);

    // Node* target = root->right->right->left; // 9
    Node* target = root->right->right->right; //-1
    cout<<"Inorder successor is : "<<in_pred(root, target);

    return 0;
}
