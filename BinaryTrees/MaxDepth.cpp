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
    int solve(TreeNode *root){
        if(root){
            int left = solve(root->left);
            int right = solve(root->right);
            return 1 + max(left, right);
        }
        return 0;
    }
public:
    int maxDepth(TreeNode* root) {
        return solve(root);
    }
};