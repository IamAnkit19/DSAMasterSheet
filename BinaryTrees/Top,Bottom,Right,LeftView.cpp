#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    // Top view
    vector<int> topView(Node *root) {
        // code here
        map<int, Node*> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            pair<Node*, int> p = q.front();
            q.pop();
            Node *node = p.first; 
            int hd = p.second;
            if(mp.find(hd) == mp.end()){
                mp[hd] = node;
            }
            if(node->left){
                q.push({node->left, hd-1});
            }
            if(node->right){
                q.push({node->right, hd+1});
            }
        }
        vector<int> ans;
        for(auto p : mp){
            ans.push_back(p.second->data);
        }
        return ans;
    }
    
    // Bottom view
    vector<int> bottomView(Node *root) {
        // code here
        map<int, Node*> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            pair<Node*, int> p = q.front();
            q.pop();
            Node *node = p.first;
            int hd = p.second;
            mp[hd] = node;
            if(node->left){
                q.push({node->left, hd-1});
            }
            if(node->right){
                q.push({node->right, hd+1});
            }
        }
        vector<int> ans;
        for(auto p : mp){
            ans.push_back(p.second->data);
        }
        return ans;
    }

    // Right view
    vector<int> ans;
    void rPreorder(Node *root, int level){
        if(root){
            if(level == ans.size())
                ans.push_back(root->data);
            rPreorder(root->right, level+1);
            rPreorder(root->left, level+1);
        }
    }
    vector<int> rightView(Node *root) {
        //  code here
        rPreorder(root, 0);
        return ans;
    }

    // Left view
    vector<int> ans;
    void preorder(Node *root, int level){
        if(root){
            if(ans.size() == level){
                ans.push_back(root->data);
            }
            preorder(root->left, level+1);
            preorder(root->right, level+1);
        }
    }
  public:
    vector<int> leftView(Node *root) {
        // code here
        preorder(root, 0);
        return ans;
    }
};