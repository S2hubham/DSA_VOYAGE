#include<bits/stdc++.h>
using namespace std;


// Iterative Post-Order traversal on Binary tree
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


void itr_postorder_traversal(Node* root){
    // using two stacks
    if(root == NULL)    return;
    stack<Node*> s1;
    stack<Node*> s2;
    Node* node = root;
    s1.push(node);
    while(!s1.empty()){
        s2.push(s1.top());
        node = s1.top();
        s1.pop();
        if(node->left)  s1.push(node->left);
        if(node->right) s1.push(node->right);
    }

    while(!s2.empty()){
        node = s2.top();
        s2.pop();
        cout<<node->data<<" ";
    }

    // TC : O(n)
    // SC : O(2n)
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

    itr_postorder_traversal(root);
    
    return 0;
}