#include<bits/stdc++.h>
using namespace std;

class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        if(head == NULL || head->next == NULL){
            return 0;
        }
        Node *slow = head, *fast = head;
        do{
            slow = slow->next;
            fast = fast->next->next;
        }while(slow != fast && fast != NULL && fast->next != NULL);
        if(fast == NULL || fast->next == NULL){
            return 0;
        }
        int count = 0;
        do{
            count++;
            slow = slow->next;
            fast = fast->next->next;
        }while(slow != fast);
        return count;
    }
};