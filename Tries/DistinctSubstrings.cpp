#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }
    void put(char ch, Node *node){
        links[ch-'a'] = node;
    }
    Node *get(char ch){
        return links[ch-'a'];
    }
};
class Solution {
  public:
    int countSubs(string& s) {
        // code here
        int n = s.length();
        int count = 0;
        Node *root = new Node();
        for(int i=0; i<n; i++){
            Node *node = root;
            for(int j=i; j<n; j++){
                if(!node->containsKey(s[j])){
                    node->put(s[j], new Node());
                    count++;
                }
                node = node->get(s[j]);
            }
        }
        return count;
    }
};