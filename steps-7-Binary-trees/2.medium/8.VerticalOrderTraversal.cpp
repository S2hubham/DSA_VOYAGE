#include<bits/stdc++.h>
using namespace std;


// vertical traversal Binary Tree
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


vector<vector<int>> vertical(Node* root){
    queue<pair<Node*, pair<int, int>>> q;  // q<node, <vertical, level>>
    map<int, map<int, multiset<int>>> mpp;  // map<vertical, map<level, multiset<node values>>>

    q.push({root, {0, 0}});

    while(!q.empty()){
        auto p = q.front();
        q.pop();

        Node* temp = p.first;
        int x = p.second.first, y = p.second.second;

        mpp[x][y].insert(temp->data);

        if(temp->left){
            q.push({temp->left, {x - 1, y + 1}});
        }
        if(temp->right){
            q.push({temp->right, {x + 1, y + 1}});
        }
    }

    vector<vector<int>> ans;

    for(auto p : mpp){
        vector<int> col;
        for(auto q : p.second){
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }

    return ans;
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4); 
    root->left->right = new Node(10); 
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);  

    root->right = new Node(3);
    root->right->left = new Node(9); 
    root->right->right = new Node(10); 

    vector<vector<int>> ans = vertical(root);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}