#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        bool lToR = true;
        while(!q.empty()){
            int length = q.size();
            vector<int> temp(length);
            for(int i=0; i<length; i++){
                TreeNode *node = q.front();
                q.pop();
                int index = lToR ? i : (length - 1 - i);
                temp[index] = node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            lToR = !lToR;
            ans.push_back(temp);
        }
        return ans;
    }
};