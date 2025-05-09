#include<bits/stdc++.h>
using namespace std;


// Height of a Binary Tree
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


// approach 1
int height1(Node* root){
    // base case
    if(root == NULL){
        return 0;
    }

    int l = height(root->left);
    int r = height(root->right);

    return (1 + max(l, r));
}


// approach 2
int height2(Node* root){
    if(root == NULL)    return 0;

    queue<Node*> q;
    int height;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            Node* temp = q.front();
            q.pop();
            if(temp->left)  q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        height++;
    }

    return height;
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

    cout<<"Max height of tree is : "<<height2(root);
    
    return 0;
}