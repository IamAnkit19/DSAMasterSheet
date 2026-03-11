#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        Node *ptr = head;
        while(ptr != NULL){
            Node *newNode = new Node(ptr->val);
            Node *temp = ptr->next;
            ptr->next = newNode;
            newNode->next = temp;
            ptr = temp;
        }
        ptr = head;
        Node *temp = head->next, *newHead = head->next;
        while(ptr != NULL){
            if(ptr->random == NULL){
                temp->random = NULL;
            }
            else{
                temp->random = ptr->random->next;
            }
            ptr = ptr->next->next;
            if(temp->next != NULL){
                temp = temp->next->next;
            }
        }
        ptr = head;
        temp = newHead;
        while(ptr != NULL){
            ptr->next = temp->next;
            if(temp->next != NULL){
                temp->next = temp->next->next;
            }
            temp = temp->next;
            ptr = ptr->next;
        }
        return newHead;
    }
};