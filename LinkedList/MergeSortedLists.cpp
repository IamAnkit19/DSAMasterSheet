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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ans = NULL, *ansHead = NULL, *ptr1 = list1, *ptr2 = list2;
        while(ptr1 != NULL && ptr2 != NULL){
            if(ptr1->val <= ptr2->val){
                if(ans == NULL){
                    ans = ptr1;
                }
                else{
                    ans->next = ptr1;
                    ans = ptr1;
                }
                ptr1 = ptr1->next;
                ans->next = NULL;
            }
            else{
                if(ans == NULL){
                    ans = ptr2;
                }
                else{
                    ans->next = ptr2;
                    ans = ptr2;
                }
                ptr2 = ptr2->next;
                ans->next = NULL;
            }
            if(ansHead == NULL){
                ansHead = ans;
            }
        }
        if(ptr1 != NULL){
            if(ans == NULL){
                ansHead = ptr1;
            }
            else{
                ans->next = ptr1;
            }
        }
        if(ptr2 != NULL){
            if(ans == NULL){
                ansHead = ptr2;
            }
            else{
                ans->next = ptr2;
            }
        }
        return ansHead;
    }
};