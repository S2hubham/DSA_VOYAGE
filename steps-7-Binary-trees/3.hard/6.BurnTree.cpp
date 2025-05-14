#include<bits/stdc++.h>
using namespace std;


// Time taken to burn binary tree completely from give node
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


void markParent(Node* root, unordered_map<Node*, Node*> &parent){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp->left){
            q.push(temp->left);
            parent[temp->left] = temp;
        }
        if(temp->right){
            q.push(temp->right);
            parent[temp->right] = temp;
        }
    }
}


int fire(Node* root, Node* target){
    if(!root)   return -1;

    // step 1
    unordered_map<Node*, Node*> parent;
    markParent(root, parent);

    // step 2
    queue<Node*> q;
    q.push(target);

    unordered_map<Node*, bool> visited;
    visited[target] = true;

    int time = 0;

    while(!q.empty()){
        int size = q.size();
        bool goneToLeft = false, goneToRight = false, goneToParent = false;

        for(int i = 0; i < size; i++){
            Node* temp = q.front();
            q.pop();
            
            if(temp->left && !visited[temp->left]){
                goneToLeft = true;
                q.push(temp->left);
                visited[temp->left] = true;
            }
            if(temp->right && !visited[temp->right]){
                goneToRight = true;
                q.push(temp->right);
                visited[temp->right] = true;
            }
            if(parent[temp] && !visited[parent[temp]]){
                goneToParent = true;
                q.push(parent[temp]);
                visited[parent[temp]] = true;
            }
        }

        if(goneToLeft || goneToRight || goneToParent){
            time++;
        }
    }

    return time;

    // final 
    // TC : O(n)
    // SC : O(n)
} 


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);  
    root->left->left->right = new Node(7);
 
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    
    Node* target1 = root->left->left->right; // 5
    Node* target2 = root->left;  // 3

    cout<<"Total time taken to burn binary tree completely from give node " << target2->data << " is : " <<fire(root, target2);   
    return 0;
}