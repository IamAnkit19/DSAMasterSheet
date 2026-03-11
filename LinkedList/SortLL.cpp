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
    ListNode *findMiddle(ListNode *head){
        ListNode *slow = head, *fast = head->next; // fast is pointing to head->next because he have to stop in first middle in even length list
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *merge(ListNode *left, ListNode *right){
        ListNode *head = NULL, *ptr = NULL;
        while(left != NULL && right != NULL){
            if(left->val <= right->val){
                ListNode *temp = left;
                left = left->next;
                temp->next = NULL;
                if(head == NULL){
                    head = ptr = temp;
                }
                else{
                    ptr->next = temp;
                    ptr = temp;
                }
            }
            else{
                ListNode *temp = right;
                right = right->next;
                temp->next = NULL;
                if(head == NULL){
                    head = ptr = temp;
                }
                else{
                    ptr->next = temp;
                    ptr = temp;
                }
            }
        }
        if(left){
            if(!head){
                head = left;
            }
            else{
                ptr->next = left;
            }
        }
        else{
            if(!head){
                head = right;
            }
            else{
                ptr->next = right;
            }
        }
        return head;
    }
    ListNode *mergeSort(ListNode *head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *middle = findMiddle(head);
        ListNode *right = middle->next;
        middle->next = NULL;
        ListNode *left = head;
        left = mergeSort(left);
        right = mergeSort(right);
        return merge(left, right);
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};