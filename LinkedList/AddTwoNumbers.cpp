#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = NULL, *ptr = NULL;
        ListNode *first = l1, *second = l2;
        while(first != NULL && second != NULL){
            int temp = first->val + second->val + carry;
            carry = temp / 10;
            int digit = temp % 10;
            ListNode *newNode = new ListNode(digit);
            if(head == NULL){
                ptr = newNode;
                head = ptr;
            }
            else{
                ptr->next = newNode;
                ptr = newNode;
            }
            first = first->next;
            second = second->next;
        }
        while(first != NULL){
            int temp = first->val + carry;
            carry = temp / 10;
            int digit = temp % 10;
            ListNode *newNode = new ListNode(digit);
            if(head == NULL){
                ptr = newNode;
                head = ptr;
            }
            else{
                ptr->next = newNode;
                ptr = newNode;
            }
            first = first->next;
        }
        while(second != NULL){
            int temp = second->val + carry;
            carry = temp / 10;
            int digit = temp % 10;
            ListNode *newNode = new ListNode(digit);
            if(head == NULL){
                ptr = newNode;
                head = ptr;
            }
            else{
                ptr->next = newNode;
                ptr = newNode;
            }
            second = second->next;
        }
        if(carry){
            ListNode *newNode = new ListNode(carry);
            ptr->next = newNode;
            ptr = newNode;
        }
        return head;
    }
};