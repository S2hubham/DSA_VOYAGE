#include<bits/stdc++.h>
using namespace std;


// Create binary tree from Inorder and Preorder traversals
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


void func(unordered_map<int, int> &mapInRoot, vector<int> inorder){
    for(int i = 0; i < inorder.size(); i++){
        mapInRoot[inorder[i]] = i;
    }
}

Node* createTree(vector<int> inorder, int instart, int inend, vector<int> preorder, int prestart, int preend, unordered_map<int, int> &mapInRoot){
    // base case
    if(prestart > preend || instart > inend)    return NULL;

    Node* root = new Node(preorder[prestart]);

    int inroot = mapInRoot[preorder[prestart]];
    int left = inroot - instart;

    root->left = createTree(inorder, instart, inroot - 1, preorder, prestart + 1, prestart + left, mapInRoot);
    root->right = createTree(inorder, inroot + 1, inend, preorder, prestart + left + 1, preend, mapInRoot);

    return root;

    // TC : O(n) for all nodes
    // SC : O(2n) ~= O(n) for map and recursive stack space
}



void preorder_traversal(Node* node) {
    if(node == NULL) return;

    cout << node->data << " ";
    preorder_traversal(node->left);
    preorder_traversal(node->right);
}

void inorder_traversal(Node* node) {
    if(node == NULL) return;

    inorder_traversal(node->left);
    cout << node->data << " ";
    inorder_traversal(node->right);
}


int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};

    unordered_map<int, int> mapInRoot;
    func(mapInRoot, inorder);

    Node* root = createTree(inorder, 0, inorder.size()-1, preorder, 0, preorder.size()-1, mapInRoot);

    cout << "Inorder: ";
    inorder_traversal(root);

    cout << "\nPreorder: ";
    preorder_traversal(root);
    
    return 0;
}