#include<bits/stdc++.h>
using namespace std;

// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.
class Solution {
    void heapify(vector<int> &arr, int i, int n){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if(left < n && arr[left] > arr[largest]){
            largest = left;
        }
        if(right < n && arr[right] > arr[largest]){
            largest = right;
        }
        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(arr, largest, n);
        }
    }
  public:
    // Function to sort an array using Heap Sort.
    void heapSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        for(int i=n/2-1; i>=0; i--){
            heapify(arr, i, n);
        }
        int l = 0, r = n - 1;
        for(int r = n-1; r>=0; r--){
            swap(arr[0], arr[r]);
            heapify(arr, 0, r);
        }
    }
};