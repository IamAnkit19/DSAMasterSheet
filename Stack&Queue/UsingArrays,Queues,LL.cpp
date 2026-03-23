#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Stack
class myStack {
    Node *top;
    int n;
  public:
    myStack() {
        // Initialize your data members
        top = NULL;
        n = 0;
    }

    bool isEmpty() {
        // check if the stack is empty
        return top == NULL;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node *newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        n++;
    }

    void pop() {
        // Removes the top element of the stack
        if(top == NULL){
            return;
        }
        Node *temp = top->next;
        top->next = NULL;
        delete top;
        top = temp;
        n--;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(top == NULL){
            return -1;
        }
        return top->data;
    }

    int size() {
        // Returns the current size of the stack.
        return n;
    }
};

// Queue
class myQueue {
    Node *front, *back;
    int n;
  public:
    myQueue() {
        // Initialize your data members
        front = back = NULL;
        n = 0;
    }

    bool isEmpty() {
        // check if the queue is empty
        return front == NULL;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node *newNode = new Node(x);
        n++;
        if(front == NULL){
            front = back = newNode;
            return;
        }
        back->next = newNode;
        back = newNode;
    }

    void dequeue() {
        // Removes the front element of the queue
        if(front == NULL){
            return;
        }
        Node *temp = front;
        front = front->next;
        temp->next = NULL;
        delete temp;
        n--;
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(front == NULL){
            return -1;
        }
        return front->data;
    }

    int size() {
        // Returns the current size of the queue.
        return n;
    }
};