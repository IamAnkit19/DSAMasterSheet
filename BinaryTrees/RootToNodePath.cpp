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
    void preorder(TreeNode *root, vector<string> &ans, string path){
        if(root->left == NULL && root->right == NULL){
            if(path == ""){
                path += to_string(root->val);
            }
            else{
                path = path+"->"+to_string(root->val);
            }
            ans.push_back(path);
            return;
        }
        if(path == ""){
            path += to_string(root->val);
        }
        else{
            path = path+"->"+to_string(root->val);
        }
        if(root->left){
            preorder(root->left, ans, path);
        }
        if(root->right){
            preorder(root->right, ans, path);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<string> ans;
        preorder(root, ans, "");
        return ans;
    }
};