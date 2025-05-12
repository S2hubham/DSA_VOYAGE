#include<bits/stdc++.h>
using namespace std;


// Right view of Binary Tree
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


// Iterative approach
/* vector<int> rightView(Node* root){
    vector<int> ans;
    if(!root)   return ans;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int ele, size = q.size();

        for(int i = 0; i < size; i++){
            Node* temp = q.front();
            q.pop();

            ele = temp->data;

            if(temp->left)  q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }

        ans.push_back(ele);
    }

    return ans;

    // TC : O(n)
    // SC : O(n)
} */



// recursive approach
void func(Node* root, int lvl, vector<int> &ans){
    if(root == NULL)    return;

    // main step
    if(ans.size() == lvl){
        ans.push_back(root->data);
    }

    func(root->right, lvl + 1, ans);
    func(root->left, lvl + 1, ans);
}

vector<int> rightView(Node* root){
    vector<int> ans;
    func(root, 0, ans);
    return ans;

    // TC : O(n)
    // SC : O(n)
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->left->right->left = new Node(8); 
    root->left->right->right = new Node(9);  
 

    root->right = new Node(3);
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 

    vector<int> ans = rightView(root);   // 1 3 7 9

    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}