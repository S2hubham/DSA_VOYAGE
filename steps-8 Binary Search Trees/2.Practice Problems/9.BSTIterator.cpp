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


// Note : all the internal parts like stack and pushAll function needs to be written in private scope 
// why : bcoz they are internal helpers and external class should not be able to access them directly otherwise they can cause unnecessary modifications
// stack : if it was public anyone can push/pop elements and break the integrity
// pushAll : if it was public then external code can call it anytime with object and mess up whole workflow 


class BSTIterator{
private :
    stack<Node*> st;
    bool reverse;

    // pushAll left nodes func
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
    // parameterized constructor
    BSTIterator(Node* root){
        pushAll(root);
    }

    // hasNext func
    bool hasNext(){
        cout<< "Has next -> " <<((!st.empty()) ? "Yes" : "No") << endl;
    }

    // next func
    void next(){
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


    // TC : O(1) avg TC
    // SC : O(h) at max we are storing O(h) elements
};



int main() {
    Node* root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(9);
    root->left->left->left = new Node(1);
    root->left->right->left = new Node(5);
    root->right->left->left = new Node(8);
    root->left->right->left->left = new Node(4);

    BSTIterator x(root);
    x.next();
    x.next();
    x.next();
    x.next();
    x.hasNext();
    x.next();
    x.next();
    x.next();
    x.next();
    x.next();
    x.next();
    x.hasNext();

    return 0;
}
