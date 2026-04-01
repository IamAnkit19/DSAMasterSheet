#include<bits/stdc++.h>
using namespace std;

// Min Heap
class minHeap {
    void heapifyUp(int i){
        while(i > 0){
            int parent = (i -1) / 2;
            if(heap[i] < heap[parent]){
                swap(heap[i], heap[parent]);
                i = parent;
            }
            else{
                break;
            }
        }
    }
    void heapifyDown(int i){
        int n = heap.size();
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(left < n && heap[smallest] > heap[left]){
            smallest = left;
        }
        if(right < n && heap[smallest] > heap[right]){
            smallest = right;
        }
        if(smallest != i){
            swap(heap[smallest], heap[i]);
            heapifyDown(smallest);
        }
    }
public:
    vector<int> heap;
    // Constructor for the class.
    minHeap() {
        // Write your code here.
    }
    minHeap(int capacity) {
        heap.reserve(capacity);
    }

    // Implement the function to remove minimum element.
    int extractMinElement() {
        // Write you code here.
        if(heap.empty()){
            return -1;
        }
        int minEle = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if(!heap.empty()){
            heapifyDown(0);
        }
        return minEle;
    }

    // Implement the function to delete an element.
    void deleteElement(int ind) {
        // Write you code here.
        if(ind < 0 || ind >= heap.size()){
            return;
        }
        heap[ind] = heap.back();
        heap.pop_back();
        if(ind < heap.size()){
            heapifyUp(ind);
            heapifyDown(ind);
        }
    }

    // Implement the function to insert 'val' in the heap.
    void insert(int val) {
        // Write you code here.
        heap.push_back(val);
        heapifyUp(heap.size()-1);
    }
};

// Max Heap
// Some changes in min heap can convert it into max heap