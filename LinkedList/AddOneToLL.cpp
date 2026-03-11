#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
    Node* reverseList(Node* head) {
        // Iterative
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node *prev = NULL, *ptr = head, *nextElement = head->next;
        while(nextElement != NULL){
            ptr->next = prev;
            prev = ptr;
            ptr = nextElement;
            nextElement = nextElement->next;
        }
        ptr->next = prev;
        head = ptr;
        return head;
    }
  public:
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        head = reverseList(head);
        Node *ptr = head, *prev = NULL;
        // ptr->data = ptr->data + 1;
        int carry = 1;
        while(ptr != NULL){
            int sum = ptr->data + carry;
            int digit = sum % 10;
            carry = sum / 10;
            ptr->data = digit;
            prev = ptr;
            ptr = ptr->next;
        }
        if(carry){
            Node *newNode = new Node(carry);
            prev->next = newNode;
        }
        return reverseList(head);
    }
};