#include<bits/stdc++.h>
using namespace std;


// All in one traversal on Binary tree
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


vector<vector<int>> itr_postorder_traversal(Node* root){
    vector<int> preorder, inorder, postorder;
    if(root == NULL)    return {preorder, inorder, postorder};

    stack<pair<Node*, int>> st;
    st.push({root, 1});

    while(!st.empty()){
        auto& it = st.top();
        if(it.second == 1){
            preorder.push_back(it.first->data);
            it.second++;
            if(it.first->left != NULL){
                st.push({it.first->left, 1});
            }
        }
        else if(it.second == 2){
            inorder.push_back(it.first->data);
            it.second++;
            if(it.first->right != NULL){
                st.push({it.first->right, 1});
            }
        }
        else{
            postorder.push_back(it.first->data);
            st.pop();
        }
    }

    vector<vector<int>> ans;
    ans.push_back(preorder);
    ans.push_back(inorder);
    ans.push_back(postorder);

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

    vector<vector<int>> ans = itr_postorder_traversal(root);

    vector<int> preorder, inorder, postorder;
    vector<string> names = {"Pre-Order", "In-Order", "Post-Order"};

    for(int i = 0; i < ans.size(); i++){
        cout << names[i] << " : ";
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<"   ";
        }
        cout<<endl<<endl;
    }
    
    return 0;
}