#include<bits/stdc++.h>
using namespace std;


// Floor in BST
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


int floor(Node* root, int key){
    int ans = -1;
    if(!root)return ans;

    Node* curr = root;

    while(curr){
        if(curr->data == key){
            ans = curr->data;
            return ans;
        }
        else if(curr->data < key){
            ans = curr->data;
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    return ans;
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

    int ans = floor(root, key);

    if(ans){
        cout<<ans<<" is the floor of "<<key;
    }
    else{
        cout<<"There is no the floor of "<<key;
    }

    return 0;
}