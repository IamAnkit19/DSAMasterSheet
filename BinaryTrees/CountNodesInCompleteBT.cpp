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
    int leftHeight(TreeNode *root){
        int count = 0;
        while(root){
            count++;
            root = root->left;
        }
        return count;
    }
    int rightHeight(TreeNode *root){
        int count = 0;
        while(root){
            count++;
            root = root->right;
        }
        return count;
    }
public:
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int left = leftHeight(root);
        int right = rightHeight(root);
        if(left == right){
            return (1 << left) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};