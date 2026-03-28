#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    // Inorder
    vector<int> inOrder(Node* root) {
        // code here
        vector<int> inorder;
        Node *curr = root;
        while(curr){
            if(!curr->left){
                inorder.push_back(curr->data);
                curr = curr->right;
            }
            else{
                Node *prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                if(!prev->right){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    inorder.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
    // Preorder
    vector<int> preOrder(Node* root) {
        // code here
        vector<int> preorder;
        Node *curr = root;
        while(curr){
            if(!curr->left){
                preorder.push_back(curr->data);
                curr = curr->right;
            }
            else{
                Node *prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                if(!prev->right){
                    prev->right = curr;
                    preorder.push_back(curr->data);
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
};