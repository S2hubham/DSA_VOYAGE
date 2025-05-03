#include<bits/stdc++.h>
using namespace std;


// Iterative Pre-Order traversal on Binary tree
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


void itr_preorder_traversal(Node* node){
    stack<Node*> st;

    while(node){
        cout<<node->data<<" ";
        if(node->right){
            st.push(node->right);
        }
        if(node->left){
            node = node->left;
        }
        else if(!st.empty()){
            node = st.top();
            st.pop();
        }
        else{
            break;
        }
    }
    return;

    // TC : O(n)
    // SC : O(h)
}


int main(){
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

    itr_preorder_traversal(root);
    
    return 0;
}