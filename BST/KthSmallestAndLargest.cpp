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

// Kth-Smallest
class Solution {
    int count = 0;
    void inorder(TreeNode *root, int &k, int &ans){
        if(root){
            inorder(root->left, k, ans);
            count++;
            if(k == count){
                ans = root->val;
                return;
            }
            inorder(root->right, k, ans);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        inorder(root, k, ans);
        return ans;
    }
};


// The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
    int count = 0;
    void revinorder(Node *root, int &k, int &ans){
        if(root){
            revinorder(root->right, k, ans);
            count++;
            if(k == count){
                ans = root->data;
                return;
            }
            revinorder(root->left, k, ans);
        }
    }
  public:
    int kthLargest(Node *root, int k) {
        // Your code here
        int ans = -1;
        revinorder(root, k, ans);
        return ans;
    }
};