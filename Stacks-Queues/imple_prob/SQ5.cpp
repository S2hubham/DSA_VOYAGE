#include <bits/stdc++.h>
using namespace std;

// LFU cache

class Node {
public:
    Node *next;    
    Node *prev;    
    int key;       
    int val;       
    int cnt;       

    
    Node(int _key, int _val) {
        key = _key;
        val = _val;
        cnt = 1; 
    }
};


struct List {
    Node *head = new Node(-1, -1); 
    Node *tail = new Node(-1, -1); 
    int size;                      

    
    List() {
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    
    void addNewNode(Node *newNode) {
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;
        size++;
    }

    
    void deleteNode(Node *delNode) {
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
        size--;
    }
};


class LFUCache {
    int maxSizeCache;                      
    int minFreq;                           
    int curSize;                           
    unordered_map<int, Node*> keyNode;     
    unordered_map<int, List*> freqListMap; 

public:
    
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }

    
    void updateFreqListMap(Node *node) {
        
        keyNode.erase(node->key);
        freqListMap[node->cnt]->deleteNode(node);

        
        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++;
        }

        
        List *nextHigherFreqList = new List();
        if (freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }

        
        node->cnt += 1;
        nextHigherFreqList->addNewNode(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node; 
    }

    
    int get(int key_) {
        if (keyNode.find(key_) != keyNode.end()) {
            Node *getNode = keyNode[key_];
            int ans = getNode->val;
            updateFreqListMap(getNode); 
            return ans;
        }
        return -1; 
    }

    
    void put(int key_, int val_) {
        
        if (maxSizeCache == 0) return;

        
        if (keyNode.find(key_) != keyNode.end()) {
            Node *getNode = keyNode[key_];
            getNode->val = val_;
            updateFreqListMap(getNode);
        }
        else {
            
            if (curSize == maxSizeCache) {
                List *list = freqListMap[minFreq]; 
                keyNode.erase(list->tail->prev->key); 
                list->deleteNode(list->tail->prev); 
                curSize--;
            }
            curSize++;

            
            minFreq = 1; 
            List *listFreq = new List();
            if (freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq];
            }

            Node *newNode = new Node(key_, val_);
            listFreq->addNewNode(newNode);
            keyNode[key_] = newNode;         
            freqListMap[minFreq] = listFreq; 
        }
    }


    // Time Complexity: O(1) for get() and put() using unordered_map.
    // Space Complexity: O(n) for cache storage.
};


int main() {
    LFUCache LFU(3); 

    
    LFU.put(1, 10);
    LFU.put(2, 20);
    LFU.put(3, 30);
    LFU.put(4, 40);

    cout << LFU.get(3) << endl; 
    cout << LFU.get(2) << endl;
    cout << LFU.get(4) << endl;  

    LFU.put(5, 50); 
    LFU.put(2, 25); 

    cout << LFU.get(2) << endl; 
    cout << LFU.get(6) << endl; 

    return 0;
}




/* 

maxSizeCache → Maximum cache capacity.
minFreq → Tracks minimum frequency for LFU eviction.
curSize → Current cache size.
keyNode → Maps key → node (for fast lookup).
freqListMap → Maps frequency → list of nodes (to track nodes by access frequency).


update function
first remove from keyNode map
Remove the node from its current frequency list
Check if it was the least frequency and update minFreq.
create new freq list if doesnt exists and add the updated access count node to it with 
update both the maps



put function
if already exists just update the value and freq
if not 
    if cache is full we have to remove the node from minfreq list and update the maps
    if still size thenjust create a new node and add it to the freq 1 list always and update the maps


*/