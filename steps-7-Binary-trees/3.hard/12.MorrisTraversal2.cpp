#include<bits/stdc++.h>
using namespace std;


// Morris traversal Preorder
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
    while(curr){
        // case 1
        if(curr->left == NULL){
            cout<< curr->data << " ";
            curr = curr->right;
        }
        // case 2
        else{
            Node* lastNode = curr->left;
            while(lastNode->right && lastNode->right != curr){
                lastNode = lastNode->right;
            }

            // create thread and print
            if(lastNode->right == NULL){
                lastNode->right = curr;
                cout<< curr->data << " ";
                curr = curr->left;
            }
            // remove thread
            else{
                lastNode->right = NULL;
                curr = curr->right;
            }
        }
    }

    // TC : O(2n) each node processing + thread creation/removal
    // SC : O(1)
}


int main(){
    /* Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
 
    root->right = new Node(3); 
    // o/p -> 1 2 4 5 6 3  */
   


    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);  
 
    root->right = new Node(3);
    root->right->left = new Node(8); 
    root->right->right = new Node(9);  
    // o/p -> 1 2 4 5 6 7 3 8 9 

    morris(root);

    return 0;
}