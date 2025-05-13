#include<bits/stdc++.h>
using namespace std;


// Maximum width of a Binary Tree
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


int maxWidht(Node* root){
    int maxwidth = 0;
    if(!root)   return maxwidth;
    queue<pair<Node*, int>> q;
    q.push({root, 0});   // {root, index}

    while(!q.empty()){
        int size = q.size();
        int first = 0, last = 0, cal = 0;
        
        for(int i = 0; i < size; i++){
            auto x = q.front();
            q.pop();

            Node* temp = x.first;
            int index = x.second;

            if(i == 0)  first = index;
            if(i == (size - 1)) last = index;

            if(temp->left){
                int leftidx = (index == 0) ? 1 : (2 * (index - 1) + 1);
                q.push({temp->left, leftidx});
            }
            if(temp->right){
                int rightidx = (index == 0) ? 2 : (2 * (index - 1) + 2);
                q.push({temp->right, rightidx});
            }
        }

        maxwidth = max(maxwidth, (last - first + 1));
    }

    return maxwidth;

    // TC : O(n)
    // SC : O(n/2) ~= O(n)
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4); 
    root->left->left->left = new Node(5);
 
    root->right = new Node(3);
    root->right->right = new Node(6);  
    root->right->right->right = new Node(7);  

    cout<<"Max width of binary tree is : "<<maxWidht(root);
      
    return 0;
}