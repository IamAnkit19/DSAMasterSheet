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
    // Inorder Traversal
    void inorder(TreeNode *root, vector<int> &ans){
        if(root){
            inorder(root->left, ans);
            ans.push_back(root->val);
            inorder(root->right, ans);
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }

    // Preorder Traversal
    void preorder(TreeNode *root, vector<int> &ans){
        if(root){
            ans.push_back(root->val);
            preorder(root->left, ans);
            preorder(root->right, ans);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }

    // Postorder Traversal
    void postorder(TreeNode *root, vector<int> &ans){
        if(root){
            postorder(root->left, ans);
            postorder(root->right, ans);
            ans.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }

    // Level Order Traversal
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int length = q.size();
            ans.push_back({});
            for(int i=0; i<length; i++){
                TreeNode *node = q.front();
                q.pop();
                ans[level].push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            level++;
        }
        return ans;
    }
};