#include<bits/stdc++.h>
using namespace std;

// BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node *pre = NULL, *suc = NULL, *node = root;
        while(node){
            if(node->data < key){
                pre = node;
                node = node->right;
            }
            else if(node->data > key){
                suc = node;
                node = node->left;
            }
            else{
                if(node->left){
                    Node *temp = node->left;
                    while(temp->right){
                        temp = temp->right;
                    }
                    pre = temp;
                }
                if(node->right){
                    Node *temp = node->right;
                    while(temp->left){
                        temp = temp->left;
                    }
                    suc = temp;
                }
                break;
            }
        }
        return {pre, suc};
    }
};