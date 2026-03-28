#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
    Node *buildTree(vector<int> &inorder, int si, int ei, vector<int> &preorder, int sp, int ep, map<int, int> &mp){
        if(si > ei || sp > ep){
            return NULL;
        }
        Node *root = new Node(preorder[sp]);
        int inRoot = mp[root->data];
        int numsLeft = inRoot - si;
        root->left = buildTree(inorder, si, inRoot-1, preorder, sp+1, sp+numsLeft, mp);
        root->right = buildTree(inorder, inRoot+1, ei, preorder, sp+numsLeft+1, ep, mp);
        return root;
    }
  public:
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        map<int, int> mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return buildTree(inorder, 0, inorder.size()-1, preorder, 0, preorder.size()-1, mp);
    }
};