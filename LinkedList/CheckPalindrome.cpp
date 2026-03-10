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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *halfReverse = reverseList(slow);
        ListNode *first = head, *second = halfReverse;
        while(first != NULL && second != NULL){
            if(first->val != second->val){
                halfReverse = reverseList(halfReverse);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        halfReverse = reverseList(halfReverse);
        return true;
    }
};