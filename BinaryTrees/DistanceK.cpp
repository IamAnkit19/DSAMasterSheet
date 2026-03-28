#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<int> findDistance(TreeNode *target, map<TreeNode*, TreeNode*> &parent, int k){
        map<TreeNode*, bool> visited;
        int distance = 0;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        vector<int> ans;
        while(!q.empty()){
            int size = q.size();
            int isAdded = false;
            for(int i=0; i<size; i++){
                TreeNode *node = q.front();
                q.pop();
                if(parent.find(node) != parent.end() && parent[node] != NULL && !visited[parent[node]]){
                    if(distance+1 == k){
                        ans.push_back(parent[node]->val);
                    }
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                    isAdded = true;
                }
                if(node->left && !visited[node->left]){
                    if(distance+1 == k){
                        ans.push_back(node->left->val);
                    }
                    visited[node->left] = true;
                    q.push(node->left);
                    isAdded = true;
                }
                if(node->right && !visited[node->right]){
                    if(distance+1 == k){
                        ans.push_back(node->right->val);
                    }
                    visited[node->right] = true;
                    q.push(node->right);
                    isAdded = true;
                }
            }
            if(isAdded){
                distance++;
            }
        }
        return ans;
    }
    void findParent(TreeNode *root, map<TreeNode*, TreeNode*> &parent){
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = NULL;
        while(!q.empty()){
            TreeNode *node = q.front();
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
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0){
            return {target->val};
        }
        map<TreeNode*, TreeNode*> parent;
        findParent(root, parent);
        return findDistance(target, parent, k);
    }
};