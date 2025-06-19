#include<bits/stdc++.h>
using namespace std;


// Serialize and deserialize Binary Tree
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


string serialize(Node* root){
    string str;
    if(!root)   return str;
    str += to_string(root->data) + ",";

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp->left){
            q.push(temp->left);
            str += to_string(temp->left->data) + ',';
        }
        else{
            str += "#,";
        }

        if(temp->right){
            q.push(temp->right);
            str += to_string(temp->right->data) + ',';
        }
        else{
            str += "#,";
        }
    }

    return str;

    // due to bfs logic
    // TC : O(n)
    // SC : O(n)
}


Node* deserialize(string data){
    if(data.size() == 0)  return NULL;

    stringstream s(data);
    string str;
    getline(s, str, ',');

    Node* root = new Node(stoi(str));

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        // process left-part by getting next token
        getline(s, str, ',');
        if(str == "#"){
            temp->left = NULL;
        }
        else{
            Node* leftnode = new Node(stoi(str));
            temp->left = leftnode;
            q.push(leftnode);
        }

        // process right-part by getting next token
        getline(s, str, ',');
        if(str == "#"){
            temp->right = NULL;
        }
        else{
            Node* rightnode = new Node(stoi(str));
            temp->right = rightnode;
            q.push(rightnode);
        }
    }
    return root;

    // due to bfs logic
    // TC : O(n)
    // SC : O(n)
}


void preorder_traversal(Node* root){
    if(!root)   return;

    cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
 
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    string str = serialize(root);
    Node* newroot = deserialize(str);

    preorder_traversal(newroot);

    return 0;
}