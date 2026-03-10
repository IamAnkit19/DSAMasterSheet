#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Solution {
    void recursiveSolve(Node *head, vector<int> &ans){
        if(head == NULL){
            return;
        }
        ans.push_back(head->data);
        recursiveSolve(head->next, ans);
    }
  public:
    vector<int> printList(Node *head) {
        // code here
        vector<int> ans;
        recursiveSolve(head, ans);
        return ans;
    }
};