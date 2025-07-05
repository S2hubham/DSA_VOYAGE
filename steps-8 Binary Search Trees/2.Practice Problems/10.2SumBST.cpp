#include<bits/stdc++.h>
using namespace std;


// BST Iterator
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


class BSTIterator{
private :
    stack<Node*> st;
    bool reverse;

    // pushAll func with both logic
    void pushAll(Node* root){
        while(root){
            st.push(root);
            if(reverse){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
    }

public :
    BSTIterator(Node* root, bool rev){
        reverse = rev;
        pushAll(root);
    }

    // next func with both logic
    int next(){
        Node* ans = st.top();
        st.pop();
        if(reverse){
            pushAll(ans->left);
        } 
        else{
            pushAll(ans->right);
        }
        return ans->data;
    }
};


class Solution{
public :
    vector<int> twoSum(Node* root, int target){
        if(!root)   return {-1, -1};
        // left
        BSTIterator x(root, false);
        // right
        BSTIterator y(root, true);

        int l = x.next();
        int r = y.next();

        while(l < r){
            if(l + r == target) return {l, r};
            else if(l + r < target) l = x.next();
            else    r = y.next();
        }

        return {-1, -1};
    }

    // TC : O(n) for single traversal
    // SC : O(1)
};


int main() {
    Node* root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(9);
    root->right->right = new Node(11);
    root->left->left->left = new Node(1);
    root->left->right->left = new Node(5);
    root->right->left->left = new Node(8);
    root->left->right->left->left = new Node(4);

    Solution s;
    vector<int> ans = s.twoSum(root, 16);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
