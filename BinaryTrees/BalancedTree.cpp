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
            int leftHeight = solve(root->left);
            int rightHeight = solve(root->right);
            if(leftHeight == -1 || rightHeight == -1 || (abs(leftHeight-rightHeight) > 1)){
                return -1;
            }
            return max(leftHeight, rightHeight) + 1;
        }
        return 0;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        return (solve(root) > 0);
    }
};