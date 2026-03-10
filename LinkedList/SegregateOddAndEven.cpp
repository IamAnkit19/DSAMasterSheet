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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        ListNode *ansHead = NULL, *ans = NULL, *odd = head;
        while(odd != NULL){
            ListNode *newNode = new ListNode(odd->val);
            if(ansHead == NULL){
                ans = newNode;
                ansHead = ans;
            }
            else{
                ans->next = newNode;
                ans = newNode;
            }
            if(odd->next)
                odd = odd->next->next;
            else
                odd = odd->next;
        }
        ListNode *even = head->next;
        while(even != NULL){
            ListNode *newNode = new ListNode(even->val);
            if(ansHead == NULL){
                ans = newNode;
                ansHead = ans;
            }
            else{
                ans->next = newNode;
                ans = newNode;
            }
            if(even->next)
                even = even->next->next;
            else
                even = even->next;
        }
        return ansHead;
    }
};