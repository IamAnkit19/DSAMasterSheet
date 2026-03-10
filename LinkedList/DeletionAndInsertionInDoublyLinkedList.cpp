#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};

class Solution {
  public:
    // Insert after pth positiion(0-based indexing)
    Node *insertAtPos(Node *head, int p, int x) {
        // code here
        Node *newNode = new Node(x);
        if(head == NULL){
            return newNode;
        }
        Node *ptr = head;
        while(p){
            ptr = ptr->next;
            p--;
        }
        newNode->next = ptr->next;
        newNode->prev = ptr;
        ptr->next = newNode;
        if(newNode->next != NULL){
            newNode->next->prev = newNode;
        }
        return head;
    }

    // Insert at beginning
    Node* insertAtFront(Node* head, int newData) {
        Node* newNode = new Node(newData);
        newNode->next = head;
        if(head != nullptr)
            head->prev = newNode;
        return newNode;
    }

    // Delete at a position (1-based indexing)
    Node* delPos(Node* head, int x) {
        // code here
        Node *ptr = head;
        while(--x && ptr){
            ptr = ptr->next;
        }
        if(ptr == head){
            head = head->next;
            if(head != NULL){
                head->prev = NULL;
                ptr->next = NULL;
            }
            return head;
        }
        Node *temp = ptr->prev;
        temp->next = ptr->next;
        if(ptr->next != NULL){
            ptr->next->prev = temp;
        }
        ptr->next = ptr->prev = NULL;
        return head;
    }
};