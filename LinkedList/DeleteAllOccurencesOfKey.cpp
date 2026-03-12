#include<bits/stdc++.h>
using namespace std;

// a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // code here
        Node *ptr = *head_ref;
        while(ptr != NULL){
            if(ptr->data == x){
                Node *temp = ptr->next;
                if(ptr == *head_ref){
                    *head_ref = temp;
                    if(temp != NULL){
                        temp->prev = NULL;
                    }
                }
                else{
                    ptr->prev->next = temp;
                    if(temp != NULL){
                        temp->prev = ptr->prev;
                    }
                }
                delete ptr;
                ptr = temp;
                continue;
            }
            ptr = ptr->next;
        }
    }
};