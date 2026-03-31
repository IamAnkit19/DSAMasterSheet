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
    bool isValid(TreeNode* root, long long lRange, long long hRange){
        if(!root){
            return true;
        }
        if(root->val <= lRange || root->val >= hRange){
            return false;
        }
        return isValid(root->left, lRange, root->val) && isValid(root->right, root->val, hRange);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};