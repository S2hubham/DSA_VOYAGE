#include<bits/stdc++.h>
using namespace std;


// ZigZag Binary Tree
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

bool isLeaf(Node* root){
    if(root == NULL)    return false;
    if(root->left == NULL && root->right == NULL)   return true;
    else    return false;
}

void addleftboundary(Node* root, vector<int> &ans){
    Node* curr = root->left;
    while(curr){
        if(!isLeaf(curr)) ans.push_back(curr->data);
        else    break;

        if(curr->left)  curr = curr->left;
        else curr = curr->right;
    }
}


void addleaf(Node* root, vector<int> &ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    if(root->left) addleaf(root->left, ans);
    if(root->right) addleaf(root->right, ans);
}


void addrightboundary(Node* root, vector<int> &ans){
    Node* curr = root->right;
    stack<int> st;
    while(curr){
        if(!isLeaf(curr))   st.push(curr->data);
        else    break;

        if(curr->right) curr = curr->right;
        else    curr = curr->left;  
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
}


vector<int> boundary(Node* root){
    vector<int> ans;
    if(!root)   return ans;
    if(!isLeaf(root))   ans.push_back(root->data);
    // step 1
    addleftboundary(root, ans);
    // step 2
    addleaf(root, ans);
    // step 3
    addrightboundary(root, ans);

    return ans;

    // TC : O(h + n + h)  leftB + leafnodes(inorder) + rightB
    // SC : O(n) auxiliary space
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

    vector<int> ans = boundary(root);

    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}


