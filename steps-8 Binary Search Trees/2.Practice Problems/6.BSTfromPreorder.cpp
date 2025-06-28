#include<bits/stdc++.h>
using namespace std;


// Construct BST from preorder traversal
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


/* 
// my approach of getting idx and then passing required preorder only similar to creating BT approach
// but this add extra time and makes TC : O(n x n) which is worst so dont go with this 

int getIdx(vector<int> &preorder, int num, int ind){
    for(int i = ind + 1; i < preorder.size(); i++){
        if(preorder[i] > num)   return i - 1;
    }
    return ind;
}

Node* createBST(vector<int> &preorder, int start, int end){
    if(start > end)  return NULL;
    
    Node* root = new Node(preorder[start]);

    int idx = getIdx(preorder, preorder[start], start);

    root->left = createBST(preorder, start + 1, idx);
    root->right = createBST(preorder, idx + 1, end);

    return root;
} */



// better approach with range / upper bound logic
Node* createBST(vector<int> &preorder, int &idx, int ub){
    if(idx == preorder.size() || preorder[idx] > ub)  return NULL;

    Node* root = new Node(preorder[idx++]);

    root->left = createBST(preorder, idx, root->data);
    root->right = createBST(preorder, idx, ub);

    return root;

    // TC : O(3n) ~= O (n)
    // SC : O(n)
}


void preorder_traversal(Node* root){
    if(!root)   return;

    cout<< root->data <<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}


int main() {
    
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    // vector<int> preorder = {1, 3};
    cout<<"Newly created tree is : \n";
    // Node* root = createBST(preorder, 0, preorder.size()-1);
    // preorder_traversal(root);

    int idx = 0;
    Node* root = createBST(preorder, idx, INT_MAX);
    preorder_traversal(root);

    return 0;
}
