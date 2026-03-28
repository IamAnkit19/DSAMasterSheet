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
    // Space Complexity O(2n)
    // bool path(TreeNode *root, vector<TreeNode*> &ans, TreeNode* node){
    //     if(root == NULL){
    //         return false;
    //     }
    //     ans.push_back(root);
    //     if(root == node){
    //         return true;
    //     }
    //     if(path(root->left, ans, node)) return true;
    //     if(path(root->right, ans, node)) return true;
    //     ans.pop_back();
    //     return false;
    // }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // vector<TreeNode*> path1, path2;
        // path(root, path1, p);
        // path(root, path2, q);
        // int i=0;
        // TreeNode *ans = NULL;
        // int size = min(path1.size(), path2.size());
        // while(i < size){
        //     if(path1[i] != path2[i]){
        //         break;
        //     }
        //     ans = path1[i];
        //     i++;
        // }
        // return ans;

        // Recursive and optimized approach
        if(!root || root == p || root == q){
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if(left == NULL){
            return right;
        }
        if(right == NULL){
            return left;
        }
        return root;
    }
};