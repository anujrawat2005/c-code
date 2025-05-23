#include <iostream>
using namespace std;
class TrieNode{
    public:
    char value;
    bool isTerminal;
    TrieNode children[26];
    
    TrieNode(char val){
        this->value = val;
        for(int i =0;i<26;i++){
            children[i] = NULL
        }
        this->isTerminal = false;
    }
};

void insertword(TrieNode* root,string word){
    if(word.length()==0){
        root->isTerminal = true;
        return;
    }
    char  ch = word[0];
    int index = ch-'a';
    TrieNode* child;
    if(root->children[index]!=NULL){
        child = root->children[index];
    }
    else{
        child = new TrieNode(ch);
        root->children[index] = child;
    }
    insertword(child,word.substr(1));
}

bool searchword(TrieNode* root,string word){
    if(word.length()==0){
        return root->isTerminal;
    }
    char ch = word[0];
    int index = ch-'a';
    TrieNode* child;
    
    if(root->children[index]!=NULL){
        child = root->children[index];
    }
    else{
        return false;
    }
    bool recursionans = searchword(child,word.substr(1));
    return recursionans;
}
