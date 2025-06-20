#include<bits/stdc++.h>
using namespace std;


// Morris traversal Inorder
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


void morris(Node* root){
    if(!root)   return;

    Node* curr = root;
    unordered_map<Node*, bool> visited;

    while(curr){
        // case 1
        if(curr->left == NULL){
            cout<< curr->data << " ";
            curr = curr->right;
        }
        // case 2
        else{
            Node* prev = curr->left;
            while(prev->right && prev->right != curr){
                prev = prev->right;
            }

            // create thread
            if(prev->right == NULL){
                prev->right = curr;
                curr = curr->left;
            }
            // remove thread
            else{
                prev->right = NULL;
                cout<< curr->data << " ";
                curr = curr->right;
            }
        }
    }

    // TC : O(n)
    // SC : O(1)
}


int main(){
    /* Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
 
    root->right = new Node(3); 
    // o/p -> 4 2 6 5 1 3
    */


    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);  
 
    root->right = new Node(3);
    root->right->left = new Node(8); 
    root->right->right = new Node(9);  
    // o/p -> 4 2 6 5 7 1 8 3 9 

    morris(root);

    return 0;
}