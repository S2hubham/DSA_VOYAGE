#include<bits/stdc++.h>
using namespace std;


// Delete node in BST
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* findLastRight(Node* root){
    while(root->right){
        root = root->right;
    }
    return root;
}

Node* helper(Node* root){
    if(root->left == NULL){
        return root->right;
    }
    else if(root->right == NULL){
        return root->left;
    }
    Node* rc = root->right;
    Node* lastright = findLastRight(root->left);
    lastright->right = rc;
    return root->left;
}

Node* del(Node* root, int target){
    if(!root)   return root;

    if(root->data == target)    return helper(root);

    Node* dummy = root;
    while(root){
        if(target > root->data){
            if(root->right && root->right->data == target){
                root->right = helper(root->right);
                break;
            }
            else{
                root = root->right;
            }
        }
        else{
            if(root->left && root->left->data == target){
                root->left = helper(root->left);
                break;
            }
            else{
                root = root->left;
            }
        }
    }
    return dummy;

    // TC : O(log n)
    // SC : O(1)
}


void preorder_traversal(Node* root){
    if(!root)   return;

    cout<< root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}


int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(2); 
    root->left->right = new Node(4);

    root->right = new Node(6); 
    root->right->right = new Node(7);

    cout << "Before : ";
    preorder_traversal(root);

    // int target = 5;
    int target = 3;
    root = del(root, target);

    cout << "\n\nAfter  : ";
    preorder_traversal(root);

    return 0;
}
