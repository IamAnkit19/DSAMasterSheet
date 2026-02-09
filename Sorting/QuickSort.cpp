#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low < high){
            int idx = partition(arr, low, high);
            quickSort(arr, low, idx - 1);
            quickSort(arr, idx + 1, high);
        }
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        // code here
        int pivot = arr[low];
        int i = low, j = high;
        while(i < j){
            while(i <= high - 1 && arr[i] <= pivot){
                i++;
            }
            while(j >= low + 1 && arr[j] > pivot){
                j--;
            }
            if(i < j){
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[low], arr[j]);
        return j;
    }
};