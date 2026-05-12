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
    void setFlag(){
        flag = true;
    }
    bool isSetFlag(){
        return flag;
    }
};
class Trie{
    Node *root = NULL;
public:
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node *node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setFlag();
    }
    bool isPossible(string word){
        Node *node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
            if(!node->isSetFlag()){
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        int maxLength = 0;
        string ans = "";
        Trie *trie = new Trie();
        for(string str : words){
            trie->insert(str);
        }
        for(string str : words){
            if(trie->isPossible(str)){
                int len = str.length();
                if(len > maxLength){
                    maxLength = len;
                    ans = str;
                }
                else if(len == maxLength && str < ans){
                    ans = str;
                }
            }
        }
        return ans;
    }
};