#include<bits/stdc++.h>
using namespace std;

// Two Numbers
struct Node{
    Node *links[2];
    Node(){
        links[0] = links[1] = NULL;
    }
    bool containsKey(int bit){
        return links[bit] != NULL;
    }
    void put(int bit, Node *node){
        links[bit] = node;
    }
    Node *get(int bit){
        return links[bit];
    }
};
class Trie{
    Node *root = NULL;
public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node *node = root;
        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node);
            }
            node = node->get(bit);
        }
    }
    int getMax(int num){
        Node *node = root;
        int maxNum = 0;
        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1;
            if(node->containsKey(1-bit)){
                maxNum = maxNum | (1 << i);
                node = node->get(1-bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        // Brute Force
        // int n = nums.size();
        // int ans = 0;
        // for(int i=0; i<n; i++){
        //     for(int j=i; j<n; j++){
        //         int temp = nums[i] ^ nums[j];
        //         if(temp > ans){
        //             ans = temp;
        //         }
        //     }
        // }
        // return ans;

        // Using Trie (Optimized)
        Trie *trie = new Trie();
        int n = nums.size();
        for(int i=0; i<n; i++){
            trie->insert(nums[i]);
        }
        int maxXor = 0;
        for(int i=0; i<n; i++){
            maxXor = max(maxXor, trie->getMax(nums[i]));
        }
        return maxXor;
    }
};

// Element From Array
struct Node{
    Node *links[2];
    Node(){
        links[0] = links[1] = NULL;
    }
    bool containsKey(int bit){
        return links[bit] != NULL;
    }
    void put(int bit, Node *node){
        links[bit] = node;
    }
    Node *get(int bit){
        return links[bit];
    }
};
class Trie{
    Node *root = NULL;
public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node *node = root;
        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node);
            }
            node = node->get(bit);
        }
    }
    int getMax(int num){
        Node *node = root;
        int maxNum = 0;
        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1;
            if(node->containsKey(1-bit)){
                maxNum = maxNum | (1 << i);
                node = node->get(1-bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> offlineQueries;
        int q = queries.size();
        for(int i=0; i<q; i++){
            offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(offlineQueries.begin(), offlineQueries.end());
        vector<int> ans(q, -1);
        int idx = 0;
        int n = nums.size();
        Trie *trie = new Trie();
        for(int i=0; i<q; i++){
            int ai = offlineQueries[i].first;
            int xi = offlineQueries[i].second.first;
            int qIdx = offlineQueries[i].second.second;
            while(idx < n && nums[idx] <= ai){
                trie->insert(nums[idx]);
                idx++;
            }
            if(idx != 0){
                ans[qIdx] = trie->getMax(xi);
            }
        }
        return ans;
    }
};