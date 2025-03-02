#include<bits/stdc++.h>
using namespace std;

// LRU cache

class LRUCache{
public : 
    class Node{
    public : 
        Node* next;
        Node* prev;
        int key;
        int val;
    
        Node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };


    Node * head = new Node(-1, -1);
    Node * tail = new Node(-1, -1);


    int cap;
    unordered_map<int, Node*> mpp;


    // constructor for initializing capacity
    LRUCache(int capacity){
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }


    // adding new node functionality
    void addNewNode(Node * newNode){
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;
    }

    // deleting the given node functionality
    void deleteNode(Node * delNode){
        delNode->next->prev = delNode->prev;
        delNode->prev->next = delNode->next;
    }


    // getting value of given key functionality
    int get(int key_){
        if(mpp.find(key_) != mpp.end()){
            Node * getNode = mpp[key_];
            int ans = getNode->val;
            deleteNode(getNode);
            addNewNode(getNode);
            return ans;
        }

        return -1;
    }


    // updation functionality
    void put(int key_, int val_){
        if(mpp.find(key_) != mpp.end()){
            Node * getNode = mpp[key_];
            getNode->val = val_;
            deleteNode(getNode);
            addNewNode(getNode);
        }
        else{
            if(mpp.size() == cap){
                Node * getNode = tail->prev;
                mpp.erase(getNode->key);
                deleteNode(getNode);
            }
            Node * newNode = new Node(key_, val_);
            mpp[key_] = newNode;
            addNewNode(newNode);
        }
    }


    // TC : O(1) for if we use unordered_map
    // SC : O(n) + O(n+2)  one for map, one for nodes
};


int main(){
    LRUCache LRU(4);
    LRU.put(2, 6);
    LRU.put(4, 7);
    LRU.put(8, 11);
    LRU.put(7, 10);
    cout << LRU.get(2) << endl; // Should return 6
    cout << LRU.get(8) << endl; // Should return 11
    LRU.put(5, 6);
    cout << LRU.get(7) << endl; // Should return 10
    LRU.put(5, 7);
    cout << LRU.get(10) << endl; // Should return -1


    return 0;
}