#include<bits/stdc++.h>
using namespace std;


// Lowest common ancestor in Binary Tree
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


// route approach 
/* bool findPath(Node* root, int val, vector<int> &arr){
    if(!root)   return false;

    arr.push_back(root->data);

    if(root->data == val)   return true;

    if(findPath(root->left, val, arr) || findPath(root->right, val, arr))   return true;

    arr.pop_back();
    return false;
}


int LCA(Node* root, int x, int y){
    if(!root)   return -1;

    vector<int> arr1;
    vector<int> arr2;
    if(!findPath(root, x, arr1) || !findPath(root, y, arr2)) return -1;

    int size = min(arr1.size(), arr2.size());
    int ans;
    for(int i = 0; i < size; i++){
        if(arr1[i] == arr2[i])    ans = arr1[i];
        else    return ans;
    }
    return ans;

    // TC : O(2n)
    // SC : O(2n)
}  */


// recursive approach
Node* lca(Node* root, int x, int y){
    // base case
    if(!root || root->data == x || root->data == y)   return root;

    Node* left = lca(root->left, x, y);
    Node* right = lca(root->right, x, y);
    
    if(!left)   return right;
    else if(!right)  return left;
    else return root;

    // TC : O(n)
    // SC : O(n)
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);  
 
    root->right = new Node(3);
    root->right->left = new Node(8); 
    root->right->right = new Node(9);  

    // cout<<"Lowest common ancestor is : "<<LCA(root, 4, 7);
    cout<<"Lowest common ancestor is : "<<lca(root, 4, 9);
      
    return 0;
}