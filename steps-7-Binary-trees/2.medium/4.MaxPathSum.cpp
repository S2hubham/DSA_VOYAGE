#include<bits/stdc++.h>
using namespace std;


// Maximum path sum of Binary Tree
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


int func(Node* root, int &maxi){
    // base case 
    if(root == NULL)    return 0;

    int leftsum = func(root->left, maxi);
    int rightsum = func(root->right, maxi);

    if(leftsum < 0) leftsum = 0;
    if(rightsum < 0)    rightsum = 0;

    maxi = max(maxi, leftsum + root->data + rightsum);  // this is to keep the max path

    return (root->data + max(leftsum, rightsum));  // return only best path with above optimisation

    // TC : O(n)
    // SC : O(h) ~= O(n)
}


int main(){
    Node* root = new Node(15);
    root->left = new Node(10); 

    root->right = new Node(20);
    root->right->left = new Node(-30); 
    root->right->right = new Node(-15);

    int maxi = 0;
    func(root, maxi);
    cout<<"Maximum path : "<<maxi;

    return 0;
}