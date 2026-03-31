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
    // Insert
    Node* insert(Node* root, int key) {
        //  code  here
        Node *node = root;
        while(node){
            if(node->data > key){
                if(!node->left){
                    node->left = new Node(key);
                    break;
                }
                else{
                    node = node->left;
                }
            }
            else{
                if(node->right){
                    node = node->right;
                }
                else{
                    node->right = new Node(key);
                    break;
                }
            }
        }
        return root;
    }
    // Delete
    Node* delNode(Node* root, int x) {
        // code here
        Node *parent = NULL, *node = root;
        while(node){
            if(node->data == x){
                if(!node->left && !node->right){
                    if(parent){
                        if(parent->left == node){
                            parent->left = NULL;
                        }
                        else{
                            parent->right = NULL;
                        }
                    }
                    else{
                        root = NULL;
                    }
                    delete node;
                    break;
                }
                else if((!node->left && node->right)){
                    if(parent){
                        if(parent->left == node){
                            parent->left = node->right;
                        }
                        else{
                            parent->right = node->right;
                        }
                    }
                    else{
                        root = node->right;
                    }
                    node->right = NULL;
                    delete node;
                    break;
                }
                else if((node->left && !node->right)){
                    if(parent){
                        if(parent->left == node){
                            parent->left = node->left;
                        }
                        else{
                            parent->right = node->left;
                        }
                    }
                    else{
                        root = node->left;
                    }
                    node->left = NULL;
                    delete node;
                    break;
                }
                else{
                    Node *temp = node->right;
                    Node *tempParent = node;
                    while(temp->left){
                        tempParent = temp;
                        temp = temp->left;
                    }
                    swap(node->data, temp->data);
                    parent = tempParent;
                    node = temp;
                }
            }
            else if(node->data > x){
                parent = node;
                node = node->left;
            }
            else{
                parent = node;
                node = node->right;
            }
        }
        return root;
    }
};