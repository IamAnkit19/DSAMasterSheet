#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }
    void put(char ch, Node *node){
        links[ch-'a'] = node;
    }
    Node *get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};
// Basic
class Trie {
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node *node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for(int i=0; i<prefix.length(); i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// Advance
// struct Node{
//     Node *links[26];
//     int countEndWith = 0;
//     int countPrefix = 0;
//     bool containsKey(char ch){
//         return (links[ch-'a'] != NULL);
//     }
//     Node *get(char ch){
//         return links[ch-'a'];
//     }
//     void put(char ch, Node *node){
//         links[ch-'a'] = node;
//     }
//     void increaseEnd(){
//         countEndWith++;
//     }
//     void increasePrefix(){
//         countPrefix++;
//     }
//     void deleteEnd(){
//         countEndWith--;
//     }
//     void reducePrefix(){
//         countPrefix--;
//     }
//     int getEnd(){
//         return countEndWith;
//     }
//     int getPrefix(){
//         return countPrefix;
//     }
// };
// class Trie{
//     Node *root;
//     public:

//     Trie(){
//         // Write your code here.
//         root = new Node();
//     }

//     void insert(string &word){
//         // Write your code here.
//         Node *node = root;
//         for(int i=0; i<word.size(); i++){
//             if(!node->containsKey(word[i])){
//                 node->put(word[i], new Node());
//             }
//             node = node->get(word[i]);
//             node->increasePrefix();
//         }
//         node->increaseEnd();
//     }

//     int countWordsEqualTo(string &word){
//         // Write your code here.
//         Node *node = root;
//         for(int i=0; i<word.size(); i++){
//             if(!node->containsKey(word[i])){
//                 return 0;
//             }
//             node = node->get(word[i]);
//         }
//         return node->getEnd();
//     }

//     int countWordsStartingWith(string &word){
//         // Write your code here.
//         Node *node = root;
//         for(int i=0; i<word.size(); i++){
//             if(!node->containsKey(word[i])){
//                 return 0;
//             }
//             node = node->get(word[i]);
//         }
//         return node->getPrefix();
//     }

//     void erase(string &word){
//         // Write your code here.
//         Node *node = root;
//         for(int i=0; i<word.size(); i++){
//             if(node->containsKey(word[i])){
//                 node = node->get(word[i]);
//                 node->reducePrefix();
//             }
//             else{
//                 return;
//             }
//         }
//         node->deleteEnd();
//     }
// };