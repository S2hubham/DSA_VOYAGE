#include<bits/stdc++.h>
using namespace std;


// Top view of Binary Tree
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


vector<int> topView(Node* root){
    if(!root)   return {};
    queue<pair<Node*, int>> q;    // q(node, vertical line)
    map<int, int> mpp;            // mpp(vertical line, node)

    q.push({root, 0});

    while(!q.empty()){
        auto p = q.front();
        q.pop();
        
        Node* temp = p.first;
        int line = p.second;

        if(mpp.find(line) == mpp.end()){
            mpp[line] = temp->data;
        }

        if(temp->left)  q.push({temp->left, line-1});
        if(temp->right) q.push({temp->right, line+1});
    }

    vector<int> ans;
    for(auto it : mpp){
        ans.push_back(it.second);
    }

    return ans;
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->left->right->left = new Node(6);  

    root->right = new Node(3);
    root->right->right = new Node(7); 

    vector<int> ans = topView(root);

    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}