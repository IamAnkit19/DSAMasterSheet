#include<bits/stdc++.h>
using namespace std;

// Following is the class structure of the Node class:
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

Node* sortList(Node *head){
    // Write your code here.
    Node *ans = NULL, *ptr = head;
    int zeroesCount = 0, onesCount = 0, twosCount = 0;
    while(ptr != NULL){
        if(ptr->data == 0){
            zeroesCount++;
        }
        else if(ptr->data == 1){
            onesCount++;
        }
        else{
            twosCount++;
        }
        ptr = ptr->next;
    }
    ptr = NULL;
    while(zeroesCount--){
        Node *newNode = new Node(0);
        if(ans == NULL){
            ptr = newNode;
            ans = ptr;
        }
        else{
            ptr->next = newNode;
            ptr = newNode;
        }
    }
    while(onesCount--){
        Node *newNode = new Node(1);
        if(ans == NULL){
            ptr = newNode;
            ans = ptr;
        }
        else{
            ptr->next = newNode;
            ptr = newNode;
        }
    }
    while(twosCount--){
        Node *newNode = new Node(2);
        if(ans == NULL){
            ptr = newNode;
            ans = ptr;
        }
        else{
            ptr->next = newNode;
            ptr = newNode;
        }
    }
    return ans;
}