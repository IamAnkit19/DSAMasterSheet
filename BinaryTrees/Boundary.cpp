#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
    void leftBoundary(Node *root, vector<int> &ans){
        if(root && (root->left != NULL || root->right != NULL)){
            ans.push_back(root->data);
            if(root->left){
                leftBoundary(root->left, ans);
            }
            else if(root->right){
                leftBoundary(root->right, ans);
            }
        }
    }
    void inorder(Node *root, vector<int> &ans){
        if(root){
            inorder(root->left, ans);
            if(!root->left && !root->right){
                ans.push_back(root->data);
            }
            inorder(root->right, ans);
        }
    }
    void rightBoundary(Node *root, vector<int> &ans){
        if(root && (root->left != NULL || root->right != NULL)){
            if(root->right){
                rightBoundary(root->right, ans);
            }
            else if(root->left){
                rightBoundary(root->left, ans);
            }
            ans.push_back(root->data);
        }
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        if(root == NULL){
            return {};
        }
        if(!root->left && !root->right){
            return {root->data};
        }
        vector<int> ans;
        ans.push_back(root->data);
        leftBoundary(root->left, ans);
        inorder(root, ans);
        rightBoundary(root->right, ans);
        return ans;
    }
};