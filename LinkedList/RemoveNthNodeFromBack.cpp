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
    int countNode(ListNode *head){
        ListNode *ptr = head;
        int count = 0;
        while(ptr != NULL){
            count++;
            ptr = ptr->next;
        }
        return count;
    }
    ListNode *removeFromPos(ListNode *head, int n){
        ListNode *ptr = head, *prev = NULL;
        while(--n){
            prev = ptr;
            ptr = ptr->next;
        }
        if(ptr == head){
            head = head->next;
            ptr->next = NULL;
        }
        else{
            prev->next = ptr->next;
            ptr->next = NULL;
        }
        return head;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int totalNodes = countNode(head);
        n = totalNodes - n + 1;
        return removeFromPos(head, n);
    }
};