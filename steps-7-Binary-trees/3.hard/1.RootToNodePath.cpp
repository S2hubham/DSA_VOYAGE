#include<bits/stdc++.h>
using namespace std;


// Root to Node Path in Binary Tree
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


bool func(Node* root, int x, vector<int> &ans){
    // base case
    if(root == NULL)    return false;

    ans.push_back(root->data);

    if(root->data == x)   return true;

    /* bool left = func(root->left, x, ans);
    if(left)    return true;
    bool right = func(root->right, x, ans);
    if(right)   return true; */

    // better code for above approach
    if(func(root->left, x, ans) || func(root->right, x, ans))   return true;

    ans.pop_back();
    return false;

    // TC : O(n)
    // SC : O(h) ~= O(n)
}


void RootToNode(Node* root, int x){
    if(!root)   return;
    vector<int> ans;
    if(func(root, x, ans)){
        cout<<"Path to the node is : ";
        for(int i = 0; i < ans.size(); i++){
            cout<<ans[i]<<" ";
        }
    }
    else{
        cout<<"No such node found";
    }

    // TC : O(n)
    // SC : O(h) ~= O(n)
} 


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);  
 
    root->right = new Node(3); 

    RootToNode(root, 7);   
    return 0;
}