#include<bits/stdc++.h>
using namespace std;


// Print all the Nodes at a distance of K in a Binary Tree

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


void markParent(Node* root, unordered_map<Node*, Node*> &parent_track){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp->left){
            q.push(temp->left);
            parent_track[temp->left] = temp;
        }
        if(temp->right){
            q.push(temp->right);
            parent_track[temp->right] = temp;
        }
    }
}

vector<int> func(Node* root, Node* target, int distance){
    // step 1 -> mark the parents
    unordered_map<Node*, Node*> parent;
    markParent(root, parent);

    // step 2
    unordered_map<Node*, bool> visited;
    visited[target] = true;
    queue<Node*> q;
    q.push(target);

    int currDistance = 0;

    while(!q.empty()){
        int size = q.size();
        if(currDistance++ == distance)    break;

        for(int i = 0; i < size; i++){
            Node* temp = q.front();
            q.pop();

            if(temp->left && !visited[temp->left]){
                visited[temp->left] = true;
                q.push(temp->left);
            }
            if(temp->right && !visited[temp->right]){
                visited[temp->right] = true;
                q.push(temp->right);
            }
            if(parent[temp] &&  !visited[parent[temp]]){
                visited[parent[temp]] = true;
                q.push(parent[temp]);
            }
        }
    }
    
    vector<int> ans;
    while(!q.empty()){
        ans.push_back(q.front()->data);
        q.pop();
    }

    return ans;

    // TC : O(2n) ~= O(n)
    // SC : O(2n + 2n) ~= O(n)  for parent map + O(n) for visited + O(n) for queue + O(n) for result vector = O(4n) ~= O(n)

}


int main(){
    /* Node* root = new Node(50);
    root->left = new Node(7);
    root->left->left = new Node(3); 
    root->left->left->left = new Node(5);

    root->right = new Node(2);
    root->right->right = new Node(1);  
    root->right->right->right = new Node(30);  */


    Node* root = new Node(3);
    root->left = new Node(5);
    root->left->left = new Node(6); 
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(9);

    root->right = new Node(1);
    root->right->left = new Node(0);  
    root->right->right = new Node(8);

    Node* target = root->left;
    
    vector<int> ans = func(root, target, 1);

    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
      
    return 0;
}