#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    // Floor
    int findFloor(Node* root, int x) {
        // code here
        Node *node = root;
        int ans = -1;
        while(node){
            if(node->data == x){
                return node->data;
            }
            else if(node->data > x){
                node = node->left;
            }
            else{
                ans = max(ans, node->data);
                node = node->right;
            }
        }
        return ans;
    }
    // Ceil
    int findCeil(Node* root, int x) {
        // code here
        Node *node = root;
        int ans = -1;
        while(node){
            if(node->data == x){
                return node->data;
            }
            else if(node->data > x){
                ans = node->data;
                node = node->left;
            }
            else{
                node = node->right;
            }
        }
        return ans;
    }
};