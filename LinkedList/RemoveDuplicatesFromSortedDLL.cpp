#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        Node *ptr = head;
        while(ptr != NULL){
            if(ptr->prev != NULL && ptr->prev->data == ptr->data){
                ptr->prev->next = ptr->next;
                if(ptr->next != NULL){
                    ptr->next->prev = ptr->prev;
                }
                ptr->prev = NULL;
                Node *temp = ptr;
                ptr = ptr->next;
                temp->next = NULL;
                delete temp;
                continue;
            }
            ptr = ptr->next;
        }
        return head;
    }
};