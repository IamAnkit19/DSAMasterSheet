#include<bits/stdc++.h>
using namespace std;

class Solution {
    void merge(vector<int> &arr, int l, int mid, int r){
        int left = l, right = mid + 1;
        vector<int> temp;
        while(left <= mid && right <= r){
            if(arr[left] > arr[right]){
                temp.push_back(arr[right]);
                right++;
            }
            else{
                temp.push_back(arr[left]);
                left++;
            }
        }
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= r){
            temp.push_back(arr[right]);
            right++;
        }
        int i = l;
        for(int val : temp){
            arr[i] = val;
            i++;
        }
    }
  public:
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l >= r){
            return;
        }
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
};