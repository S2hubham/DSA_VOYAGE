#include<bits/stdc++.h>
using namespace std;


// Diameter of Binary Tree
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
/* int height(Node* root){
    // base case
    if(root == NULL)    return 0;

    int l = height(root->left);
    int r = height(root->right);

    return (1 + max(l, r));
} 

int maxdiameter;
void diameter(Node* root){
    // base case
    if(root == NULL)    return;

    int lh = height(root->left);
    int rh = height(root->right);

    maxdiameter = max(maxdiameter, lh + rh);

    diameter(root->left);
    diameter(root->right);

    // TC : O(n^2)
    // SC : O(h)
} */



// approach 2
int height(Node* root, int &maxdiameter){
    // base case 
    if(root == NULL)    return 0;

    int l = height(root->left, maxdiameter);
    int r = height(root->right, maxdiameter);

    maxdiameter = max(maxdiameter, l + r);

    return (1 + max(l, r));
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

    /* diameter(root);
    cout <<"Max Diameter of tree is : "<<maxdiameter; */

    int maxdiameter = INT_MIN;
    height(root, maxdiameter);
    cout<<"Max Diameter of tree is : "<<maxdiameter;

    return 0;
}