#include<bits/stdc++.h>
using namespace std;


// Create binary tree from Inorder and Postorder traversals
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


void func(unordered_map<int, int> &inMap, vector<int> inorder){
    for(int i = 0; i < inorder.size(); i++){
        inMap[inorder[i]] = i;
    }
}


Node* createTree(vector<int> inorder, int instart, int inend, vector<int> postorder, int poststart, int postend, unordered_map<int, int> &inMap){
    // base case
    if(instart > inend || poststart > postend)  return NULL;

    Node* root = new Node(postorder[postend]);
    int inroot = inMap[postorder[postend]];
    int left = inroot - instart;

    root->left = createTree(inorder, instart, inroot - 1, postorder, poststart, poststart + left - 1, inMap);
    root->right = createTree(inorder, inroot + 1, inend, postorder, poststart + left, postend - 1, inMap);

    return root;

    // TC : O(n) for all nodes
    // SC : O(2n) ~= O(n) for map and recursive stack space
}


void inorder_traversal(Node* root){
    if(!root)   return;

    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}

void postorder_traversal(Node* root){
    if(!root)   return;

    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->data << " ";
}


int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    unordered_map<int, int> inMap;
    func(inMap, inorder);

    Node* root = createTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inMap);

    cout << "Inorder: ";
    inorder_traversal(root);

    cout << "\nPostorder: ";
    postorder_traversal(root);
    
    return 0;
}