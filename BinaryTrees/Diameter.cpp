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
    int diameter(TreeNode *root, int &maxHeight){
        if(root){
            int lHeight = diameter(root->left, maxHeight);
            int rHeight = diameter(root->right, maxHeight);
            maxHeight = max(maxHeight, lHeight+rHeight);
            return 1 + max(lHeight, rHeight);
        }
        return 0;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        diameter(root, d);
        return d;
    }
};