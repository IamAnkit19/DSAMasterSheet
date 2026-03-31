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
    TreeNode *solve(vector<int> &preorder, int &idx, int ub){
        if(idx >= preorder.size() || preorder[idx] > ub){
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[idx++]);
        root->left = solve(preorder, idx, root->val);
        root->right = solve(preorder, idx, ub);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return solve(preorder, idx, INT_MAX);
    }
};