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
    int countNodes(ListNode *head){
        int count = 0;
        ListNode *ptr = head;
        while(ptr != NULL){
            ptr = ptr->next;
            count++;
        }
        return count;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *ptr = head;
        int totalCount = countNodes(head);
        k = k % totalCount;
        k = totalCount - k - 1;
        while(k-- && ptr != NULL){
            ptr = ptr->next;
        }
        ListNode *newHead = ptr->next;
        if(newHead != NULL){
            ListNode *temp = newHead;
            ptr->next = NULL;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = head;
            head = newHead;
        }
        return head;
    }
};