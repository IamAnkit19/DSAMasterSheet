#include<bits/stdc++.h>
using namespace std;

// LRU
struct Node{
    int key, value;
    Node *next, *prev;
    Node(int key, int value){
        this->key = key;
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache {
    unordered_map<int, Node*> mp;
    int capacity;
    Node *head, *tail;
    void insertNode(Node *node){
        node->prev = nullptr;
        node->next = head;
        if(head){
            head->prev = node;
        }
        head = node;
        if(!tail){
            tail = node;
        }
    }
    void deleteNode(Node *node){
        if(node->prev){
            node->prev->next = node->next;
        }
        else{
            head = node->next;
        }
        if(node->next){
            node->next->prev = node->prev;
        }
        else{
            tail = node->prev;
        }
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = NULL, tail = NULL;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        Node *node = mp[key];
        deleteNode(node);
        insertNode(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node *node = mp[key];
            node->value = value;
            deleteNode(node);
            insertNode(node);
        }
        else{
            Node *node = new Node(key, value);
            if((int)mp.size() == capacity){
                Node *oldTail = tail;
                deleteNode(oldTail);
                mp.erase(oldTail->key);
                delete oldTail;
            }
            insertNode(node);
            mp[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


// LFU
struct Node{
    int key, value, count;
    Node *next, *prev;
    Node(int key, int value){
        this->key = key;
        this->value = value;
        count = 1;
        next = prev = NULL;
    }
};

struct List{
    Node *head, *tail;
    int size;
    List(){
        head = tail = NULL;
        size = 0;
    }
    void insertNode(Node *node){
        node->prev = nullptr;
        node->next = head;
        if(head){
            head->prev = node;
        }
        head = node;
        if(!tail){
            tail = node;
        }
        size++;
    }
    void deleteNode(Node *node){
        if(node->prev){
            node->prev->next = node->next;
        }
        else{
            head = node->next;
        }
        if(node->next){
            node->next->prev = node->prev;
        }
        else{
            tail = node->prev;
        }
        size--;
    }
};

class LFUCache {
    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;
    int capacity, currSize, minFreq;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        currSize = 0;
        minFreq = 0;
    }

    void updateFreqList(Node *node){
        int oldCount = node->count;
        freqList[oldCount]->deleteNode(node);
        if(freqList[oldCount]->size == 0){
            freqList.erase(oldCount);
            if(minFreq == oldCount){
                minFreq++;
            }
        }
        node->count++;
        if(freqList.find(node->count) == freqList.end()){
            freqList[node->count] = new List();
        }
        freqList[node->count]->insertNode(node);
    }
    
    int get(int key) {
        if(keyNode.find(key) == keyNode.end()){
            return -1;
        }
        Node *node = keyNode[key];
        int value = node->value;
        updateFreqList(node);
        return value;
    }
    
    void put(int key, int value) {
        if(keyNode.find(key) != keyNode.end()){
            Node *node = keyNode[key];
            node->value = value;
            updateFreqList(node);
            return;
        }
        if(capacity == currSize){
            List *list = freqList[minFreq];
            Node *leastFreqUsed = list->tail;
            list->deleteNode(leastFreqUsed);
            keyNode.erase(leastFreqUsed->key);
            delete leastFreqUsed;
            currSize--;
        }
        Node *newNode = new Node(key, value);
        if(freqList.find(1) == freqList.end()){
            freqList[1] = new List();
        }
        freqList[1]->insertNode(newNode);
        keyNode[key] = newNode;
        minFreq = 1;
        currSize++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */