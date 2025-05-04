#include<bits/stdc++.h>
using namespace std;


// Iterative In-Order traversal on Binary tree
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


void itr_inorder_traversal(Node* root){
    stack<Node*> st;
    Node* node = root;

    while(node || !st.empty()){
        if(node){
            st.push(node);
            node = node->left;
        }
        else{
            // if(st.empty())  break;
            node = st.top();
            st.pop();
            cout<<node->data<<" ";
            node = node->right;
        }
    }
    return;

    // TC : O(n)
    // SC : O(n)


    /* 
    
    1.if node present push current node on stack and go left
    2.else move node to correct position by taking element from stack and del it then go right (repeat step1 / step2)
    3.stop condn -> of node and stack elements both are absent stop
    
    */
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

    itr_inorder_traversal(root);
    
    return 0;
}