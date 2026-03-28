#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    int findTime(Node *target, map<Node*, Node*> &parent){
        map<Node*, bool> visited;
        int totalTime = 0;
        queue<Node*> q;
        q.push(target);
        visited[target] = true;
        while(!q.empty()){
            int size = q.size();
            int isAdded = false;
            for(int i=0; i<size; i++){
                Node *node = q.front();
                q.pop();
                if(parent.find(node) != parent.end() && parent[node] != NULL && !visited[parent[node]]){
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                    isAdded = true;
                }
                if(node->left && !visited[node->left]){
                    visited[node->left] = true;
                    q.push(node->left);
                    isAdded = true;
                }
                if(node->right && !visited[node->right]){
                    visited[node->right] = true;
                    q.push(node->right);
                    isAdded = true;
                }
            }
            if(isAdded){
                totalTime++;
            }
        }
        return totalTime;
    }
    Node* findParent(Node *root, map<Node*, Node*> &parent, int target){
        queue<Node*> q;
        q.push(root);
        Node *tNode = NULL;
        parent[root] = NULL;
        while(!q.empty()){
            Node *node = q.front();
            if(node->data == target){
                tNode = node;
            }
            q.pop();
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        return tNode;
    }
  public:
    int minTime(Node* root, int target) {
        // code here
        map<Node*, Node*> mp;
        Node *targetNode = findParent(root, mp, target);
        return findTime(targetNode, mp);
    }
};