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
    ListNode* reverseList(ListNode* head) {
        // Iterative
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *prev = NULL, *ptr = head, *nextElement = head->next;
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ptr = head, *start = head, *end = head, *prev = NULL;
        int count = 1;
        while(ptr != NULL){
            if(ptr != NULL && count == k){
                end = ptr;
                ptr = ptr->next;
                count = 1;
                end->next = NULL;
                ListNode *newHead = reverseList(start);
                if(start == head){
                    head = newHead;
                }
                if(prev != NULL){
                    prev->next = newHead;
                }
                prev = start;
                start->next = ptr;
                start = ptr;
                continue;
            }
            ptr = ptr->next;
            count++;
        }
        return head;
    }
};