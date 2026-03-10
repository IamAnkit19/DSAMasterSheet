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

class Solution{
    public:
    vector<int> displayList(Node *head) {
        vector<int> ans;
        Node *ptr = head;
        while(ptr != NULL){
            ans.push_back(ptr->data);
            ptr = ptr->next;
        }
        return ans;
    }
};