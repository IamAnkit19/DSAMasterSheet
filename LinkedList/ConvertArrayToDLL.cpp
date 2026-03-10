#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
  public:
    Node* createDLL(vector<int>& arr) {
        // code here
        Node *head = NULL, *ptr = NULL;
        for(int i=0; i<arr.size(); i++){
            Node *newNode = new Node(arr[i]);
            if(head == NULL){
                head = newNode;
                ptr = newNode;
                continue;
            }
            newNode->prev = ptr;
            ptr->next = newNode;
            ptr = newNode;
        }
        return head;
    }
};