#include<bits/stdc++.h>
using namespace std;


// BFS traversal on Binary tree
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


vector<vector<int>> BFS(Node* node){
    queue<Node*> q;
    vector<vector<int>> ans;
    q.push(node);
    while(!q.empty()){
        vector<int> level;
        int size = q.size();

        for(int i = 0; i < size; i++){
            Node* temp = q.front();
            q.pop();

            if(temp->left)  q.push(temp->left);
            if(temp->right) q.push(temp->right);

            level.push_back(temp->data);
        }
        ans.push_back(level);
    }
    return ans;
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

    vector<vector<int>> ans = BFS(root);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}