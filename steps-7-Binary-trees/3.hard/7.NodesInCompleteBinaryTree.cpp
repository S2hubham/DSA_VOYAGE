#include<bits/stdc++.h>
using namespace std;


// Count total nodes in complete binary tree 
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
/* void count_nodes(Node* root, int &cnt){
    if(!root)   return;

    cnt++;
    count_nodes(root->left, cnt);
    count_nodes(root->right, cnt);

    // TC : O(n)
    // SC : O(h)
} */



// approach 2
int findlh(Node* root){
    int h = 0;
    while(root){
        h++;
        root = root->left;
    }
    return h;
}

int findrh(Node* root){
    int h = 0;
    while(root){
        h++;
        root = root->right;
    }
    return h;
}

int count_nodes(Node* root){
    if(!root)   return 0;

    int lh = findlh(root);
    int rh = findrh(root);

    if(lh == rh)    return ((1<<lh) - 1);

    return (1 + count_nodes(root->left) + count_nodes(root->right));

    // TC : O(log^2 n)
    // SC : O(logn)
    // height of complete binary tree is logn 
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);  
    root->left->right = new Node(5);
    root->left->left->left = new Node(8); 
    root->left->left->right = new Node(9); 
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
 
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    // int cnt = 0;
    // count_nodes(root, cnt);

    int cnt = count_nodes(root);

    cout<<"Total number of nodes in given complete binary tree are : "<<cnt;   
    return 0;
}