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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *first = headA, *second = headB;
        int count = 0;
        while(first != second){
            first = first->next;
            second = second->next;
            if(first == NULL){
                first = headB;
                count++;
            }
            if(second == NULL){
                second = headA;
                count++;
            }
            if(count > 2){
                return NULL;
            }
        }
        return first;
    }
};