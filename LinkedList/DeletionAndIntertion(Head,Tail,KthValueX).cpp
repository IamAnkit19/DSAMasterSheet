#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Solution {
    public:
    // Insert at end
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        Node *temp = new Node(x);
        if(head == NULL){
            return temp;
        }
        Node *ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = temp;
        return head;
    }

    // Insert at given position(0-based indexing)
    Node * insert(Node * head, int n, int pos, int val) {
        // Write your code here
        Node *ptr = head, *temp = NULL;
        while(pos){
            temp = ptr;
            ptr = ptr->next;
            pos--;
        }
        Node *newNode = new Node(val);
        if(temp == NULL){
            newNode->next = head;
            head = newNode;
            return head;
        }
        temp->next = newNode;
        newNode->next = ptr;
        return head;
    }

    // Insert at beginning
    Node *insertAtFront(Node *head, int x) {
        // Code here
        Node *newNode = new Node(x);
        if(head == NULL){
            return newNode;
        }
        newNode->next = head;
        head = newNode;
        return head;
    }

    // Delete xth node in linked list(1-based indexing)
    Node* deleteNode(Node* head, int x) {
        // code here
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        Node *ptr = head, *prev = NULL;
        while(x>1){
            prev = ptr;
            ptr = ptr->next;
            x--;
        }
        if(prev == NULL){
            head = head->next;
            return head;
        }
        if(prev == head){
            prev->next = ptr->next;
            ptr->next = NULL;
            head = prev;
            return head;
        }
        prev->next = ptr->next;
        return head;
    }

    // Delete head of a linked list
    Node *deleteHead(Node *head) {
        // code here
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        Node *ptr = head->next;
        head = NULL;
        return ptr;
    }

    // Remove last node of the linked list
    Node* removeLastNode(Node* head) {
        // code here
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        Node *ptr = head, *prev = NULL;
        while(ptr->next != NULL){
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = NULL;
        ptr = NULL;
        return head;
    }
};