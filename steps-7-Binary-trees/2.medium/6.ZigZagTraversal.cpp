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


vector<vector<int>> zigzag(Node* root){
    vector<vector<int>> zz;
    if(root == NULL)    return zz;

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> lvl(size);
        for(int i = 0; i < size; i++){
            Node* temp = q.front();
            q.pop();

            // getting correct position for inserting the node
            int index = (leftToRight) ? i : (size - 1 - i);
            lvl[index] = temp->data;

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        leftToRight = !leftToRight;
        zz.push_back(lvl);
    }

    return zz;

    // TC : O(n)
    // SC : O(n + n/2 + width/n)  zz + worst case q + worst case width lvl
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

    vector<vector<int>> ans = zigzag(root);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}


