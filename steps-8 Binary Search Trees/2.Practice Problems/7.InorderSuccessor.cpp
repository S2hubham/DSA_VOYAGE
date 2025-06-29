#include<bits/stdc++.h>
using namespace std;


// Inorder successor in BST
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
/* void inorder_traversal(Node* root, vector<int> &inorder){
    if(!root)   return;

    inorder_traversal(root->left, inorder);
    inorder.push_back(root->data);
    inorder_traversal(root->right, inorder);
}

int in_succ(Node* root, Node* target){
    vector<int> inorder;
    inorder_traversal(root, inorder);

    int ans = -1;
    for(int i = 0; i < inorder.size(); i++){
        if(inorder[i] == target->data){
            if(i + 1 < inorder.size()){
                ans = inorder[i+1];
                return ans;
            }
            else{
                break;
            }
        }
    }
    return ans;
}
 */


// approach 2 : using property of BST
int in_succ(Node* root, Node* target){
    int succ = -1;
    Node* curr = root;
    while(curr){
        if(curr->data > target->data){
            succ = curr->data;
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
    return succ;

    // TC : O(h)
    // SC : O(1)
}



int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(9);
    root->left->left->left = new Node(1);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(10);

    Node* target = root->right->right->left; // 9
    // Node* target = root->right->right->right; //-1
    cout<<"Inorder successor is : "<<in_succ(root, target);

    return 0;
}
