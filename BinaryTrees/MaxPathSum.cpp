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
    int maxSum(TreeNode *root, int &sum){
        if(root){
            int lSum = max(0,maxSum(root->left, sum));
            int rSum = max(0,maxSum(root->right, sum));
            sum = max(sum, lSum+rSum+root->val);
            return root->val + max(lSum, rSum);
        }
        return 0;
    }
public:
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        maxSum(root, sum);
        return sum;
    }
};