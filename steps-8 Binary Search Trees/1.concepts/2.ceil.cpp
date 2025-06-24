#include<bits/stdc++.h>
using namespace std;


// Ceil in BST
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


int ceil(Node* root, int key){
    int ans = -1;
    if(!root)   return ans;

    Node* curr = root;

    while(curr){
        if(curr->data == key){
            ans = curr->data;
            return ans;
        }
        else if(curr->data > key){
            ans = curr->data;
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
    return ans;

    // TC : O(log n)
    // SC : O(1)
}


int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(3); 
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);
    root->left->right = new Node(6); 
    root->left->right->right = new Node(9);
 
    root->right = new Node(13);
    root->right->left = new Node(11); 
    root->right->right = new Node(14);

    int key = 8;
    Node* target2 = new Node(100); 

    int ans = ceil(root, key);

    if(ans){
        cout<<ans<<" is the ceil of "<<key;
    }
    else{
        cout<<"There is no the ceil of "<<key;
    }

    return 0;
}