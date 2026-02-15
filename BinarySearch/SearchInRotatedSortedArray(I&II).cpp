#include<bits/stdc++.h>
using namespace std;

// I
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, h = n - 1;
        while(l <= h){
            int mid = (l + h) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[l] <= nums[mid]){
                if(nums[l] <= target && target < nums[mid]){
                    h = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            else{
                if(nums[mid] < target && target <= nums[h]){
                    l = mid + 1;
                }
                else{
                    h = mid - 1;
                }
            }
        }
        return -1;
    }
};

// II
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, h = n - 1;
        while(l <= h){
            int mid = (l + h) / 2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[l] == nums[mid] && nums[mid] == nums[h]){
                l++;
                h--;
                continue;
            }
            else if(nums[l] <= nums[mid]){
                if(nums[l] <= target && target < nums[mid]){
                    h = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            else{
                if(nums[mid] < target && target <= nums[h]){
                    l = mid + 1;
                }
                else{
                    h = mid - 1;
                }
            }
        }
        return false;
    }
};