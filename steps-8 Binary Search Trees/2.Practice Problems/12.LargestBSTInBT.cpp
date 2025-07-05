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


class NodeValue{
public :
    int size, largest, smallest;

    NodeValue(int size, int largest, int smallest){
        this->size = size;
        this->largest = largest;
        this->smallest = smallest;
    }
};


class Solution{
private :
    NodeValue largestBSTSubTreeHelper(Node* root){
        if(!root)   return NodeValue(0, INT_MIN, INT_MAX);

        auto left = largestBSTSubTreeHelper(root->left);
        auto right = largestBSTSubTreeHelper(root->right);

        if(left.largest < root->data  && root->data < right.smallest){
            return NodeValue((left.size + right.size + 1), max(root->data, right.largest), max(root->data, left.smallest));
        }
        else{
            return NodeValue(max(left.size, right.size), INT_MAX, INT_MIN);
        }
    }
public : 
    int largestBSTSubtree(Node* root){
        return largestBSTSubTreeHelper(root).size;
    }

    // TC : O(n)
    // SC : O(n)
};



int main() {
    Node* root = new Node(20);
    root->left = new Node(15);
    root->right = new Node(40);
    root->left->left = new Node(14);
    root->left->right = new Node(18);
    root->right->left = new Node(30);
    root->right->right = new Node(60);
    root->left->left->right = new Node(17);
    root->left->right->left = new Node(16);
    root->left->right->right = new Node(19);
    root->right->right->left = new Node(50);

    Solution s;
    cout<<"Size of valid BST is : "<<s.largestBSTSubtree(root);

    return 0;
}
