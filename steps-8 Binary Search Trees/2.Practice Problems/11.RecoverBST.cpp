#include<bits/stdc++.h>
using namespace std;


// BST Iterator
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
/* void inorder_traversal(Node* root, vector<int> &arr){
    if(!root)   return;

    inorder_traversal(root->left, arr);
    arr.push_back(root->data);
    inorder_traversal(root->right, arr);
}

void inorder_change(Node* root, vector<int> &arr, int &idx){
    if(!root)   return;

    inorder_change(root->left, arr, idx);
    root->data = arr[idx++];
    inorder_change(root->right, arr, idx);
} */



// aproach 2
class Solution{
private :
    Node* prev;
    Node* first;
    Node* middle;
    Node* last;

    void inorder(Node* root){
        if(!root) return;
        inorder(root->left);

        // main logic
        if(prev && (root->data < prev->data)){
            if(first){
                last = root;
            }
            else{
                first = prev;
                middle = root;
            }
        }

        prev = root;
        inorder(root->right);
    }

public :
    void recoverBST(Node* root){
        first = middle = last = NULL;
        prev = new Node(INT_MIN); 

        inorder(root);

        if(first && last)   swap(first->data, last->data);
        else if(first && middle)    swap(first->data, middle->data);
    }
};


void inorder_print(Node* root){
    if(!root)   return;

    inorder_print(root->left);
    cout<< root->data << " ";
    inorder_print(root->right);
}


int main() {
    Node* root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(4);
    root->right->left = new Node(2);

    /* vector<int> arr = {};
    inorder_traversal(root, arr);
    int idx = 0;
    sort(arr.begin(), arr.end());
    inorder_change(root, arr, idx);
    inorder_print(root); */

    Solution s;
    s.recoverBST(root);
    inorder_print(root);

    return 0;
}
