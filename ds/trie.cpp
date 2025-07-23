#include <bits/stdc++.h>
using namespace std ;

class TrieNode{
  public:
    static const int ChildCount = 26 ;
    TrieNode **children ;
    bool isEnd ;
    TrieNode(){
        children = new TrieNode*[ChildCount];
        isEnd = false ;
    }
};

class Trie {
  public:
    TrieNode *root ;
    Trie(){}
    void insert(string S){
        if(!this->root){
            this->root = new TrieNode() ;
        }
        TrieNode *cur = this->root ;
        for(int i = 0; i < S.size(); ++i){
            int idx = S[i] - 'a' ;
            if(!cur->children[idx])
                cur->children[idx] = new TrieNode() ;
            cur = cur->children[idx] ;
        }
        cur->isEnd = true ;
    }
    bool isPresent(string S){
        TrieNode *cur = root ;
        for(int i = 0; i < S.size(); ++i){
            int idx = S[i] - 'a' ;
            if(!cur->children[idx]){
                return false ;
            }
            cur = cur->children[idx] ;
        }
        return true;
    }
    void remove(string S){
        if(!this->isPresent(S))
            return ;
        TrieNode *cur = root ;
        for(int i = 0; i < S.size(); ++i){
            int idx = S[i] - 'a' ;
            cur = cur->children[idx] ;
        }
        cur->isEnd = false ;
    }
};
