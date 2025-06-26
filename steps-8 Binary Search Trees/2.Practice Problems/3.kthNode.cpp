#include<bits/stdc++.h>
using namespace std;


// Kth smallest node in BST
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

// Tip/Property : Inorder of BST prints nodes in sorted order

// Morris traversal
int kthSmallest(Node* root,  int k){
    int ans = -1;
    if(!root)   return ans;

    Node* curr = root;
    while(curr){
        if(k == 0)  break;
        if(curr->left == NULL){
            k--;
            ans = curr->data;
            curr = curr->right;
        }
        else{
            Node* last = curr->left;
            while(last->right && last->right != curr){
                last = last->right;
            }

            if(last->right == NULL){
                last->right = curr;
                curr = curr->left;
            }
            else{
                last->right = NULL;
                k--;
                ans = curr->data;
                curr = curr->right;
            }
        }
    }

    return ans;

    // TC : O(n)
    // SC : O(1)
    // not always O(n) due to early exit code
}


// Recursive inorder
void inorder(Node* root, int &counter, int &ans, int k){
    if(!root)   return;

    inorder(root->left, counter, ans, k);

    counter++;
    if(counter == k){
        ans = root->data;
        return;
    }

    inorder(root->right, counter, ans, k);

    // TC : O(n)
    // SC : O(n)
    // not always O(n) due to early exit code
}


int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(1); 
    root->left->right = new Node(4);
    root->left->left->right = new Node(2);

    root->right = new Node(7); 
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    int k = 3; 
    // cout<<"Kth smallest element is : "<<kthSmallest(root, 3);


    int counter = 0;
    int ans = -1;
    inorder(root, counter, ans, k);
    cout<<"Kth smallest element is : "<<ans;

    return 0;
}
