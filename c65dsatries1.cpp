#include <iostream>
#include<climits>
#include<vector>
using namespace std;

class Trie{
    public:
        class node {
        public:
            bool end;
            node* next[26];
            node(){
                end=false;
                for(int i=0;i<26;i++){
                    next[i]=NULL;
                }
            }
                };
    node* trie;
    Trie(){
        trie = new node();
    }
    void insert(string word){
        int i=0;
        node* it = trie;
        while(i<word.size()){
            //If these node doesn't exist create it.
            if(it->next[word[i]-'a']==NULL){
                it->next[word[i]-'a'] = new node();
            }
            it = it->next[word[i]-'a'];
            i++;
        }
        it->end=true;
    }
    bool search(string word){
        int i=0;
        node* it =trie;
        while(i<word.size()){
            if(it->next[word[i]-'a']==NULL) return false;
            it = it->next[word[i]-'a'];
            i++;
        }
        //it->end may happen as there may be encoded a longer word and we are looking for a subset of it and it would have shown true then, e.g. sarang and sara.
        return it->end;
    }
};

int main(){
    Trie *myTrie = new Trie();
    vector<string> words = {"sarang","thakare"};
    for(auto w: words){
        myTrie->insert(w);
    }
    if(myTrie->search("rang")){
        cout<<"rang is found";
    } else{
        cout<<"rang is not found";
    }
return 0;}