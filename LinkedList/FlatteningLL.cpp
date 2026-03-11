#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution {
    Node *merge(Node *first, Node *second){
        Node *ans = NULL, *ansHead = NULL;
        Node *ptr1 = first, *ptr2 = second;
        while(ptr1 && ptr2){
            if(ptr1->data <= ptr2->data){
                Node *newNode = new Node(ptr1->data);
                if(ans == NULL){
                    ans = newNode;
                    ansHead = ans;
                }
                else{
                    ans->bottom = newNode;
                    ans = newNode;
                }
                ptr1 = ptr1->bottom;
            }
            else{
                Node *newNode = new Node(ptr2->data);
                if(ans == NULL){
                    ans = newNode;
                    ansHead = ans;
                }
                else{
                    ans->bottom = newNode;
                    ans = newNode;
                }
                ptr2 = ptr2->bottom;
            }
        }
        if(ptr1 != NULL){
            if(ans != NULL){
                ans->bottom = ptr1;
            }
            else{
                return ptr1;
            }
        }
        else{
            if(ans != NULL){
                ans->bottom = ptr2;
            }
            else{
                return ptr2;
            }
        }
        return ansHead;
    }
  public:
    Node *flatten(Node *root) {
        // code here
        if(root == NULL || root->next == NULL){
            return root;
        }
        root->next = flatten(root->next);
        root = merge(root, root->next);
        return root;
    }
};