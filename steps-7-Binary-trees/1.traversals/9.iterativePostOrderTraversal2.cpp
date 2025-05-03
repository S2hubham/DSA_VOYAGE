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
    // using 1 stack
    Node* curr = root;
    Node* temp;
    stack<Node*> st;

    while(curr != NULL || !st.empty()){
        if(curr){
            st.push(curr);
            curr = curr->left;
        }
        else{
            temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                cout<<temp->data<<" ";
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    cout<<temp->data<<" ";
                }
            }
            else{
                curr = temp;
            }
        }
    }
    return;

    // TC : O(2n)
    // SC : O(n)
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