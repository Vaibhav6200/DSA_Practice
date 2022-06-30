// Using Queue to search and retrace path for '.' is taking lot of time - TimeLimit Exceeds


#include<bits/stdc++.h>
using namespace std;


class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char ch){
        data = ch;
        isTerminal = false;
        for(int i=0; i<26; i++)
            children[i]=NULL;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode('\0');      // initializing root node with null character
    }

//     Utility function to insert word in Trie
    void insertUtil(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL)
            child = root->children[index];
        else{
            root->children[index] = new TrieNode(word[0]);
            child = root->children[index];
        }
        insertUtil(child, word.substr(1));
    }
    void addWord(string word) {
        insertUtil(root, word);
    }


    bool searchUtil(TrieNode* root, string word){
        // BASE CASE
        if(word.length() == 0)
            return root->isTerminal;

        if(word[0] == '.'){
            // push(roots all childs in queue so that we can retrace other path if ans not found)
            queue<TrieNode*> q;
            for(int i=0; i<26; i++){
                if(root->children[i] != NULL)
                    q.push(root->children[i]);
            }

            // now explore each path
            while(!q.empty()){
                TrieNode* frontNode = q.front();
                q.pop();

                // now use this frontNode and use remaining string { word.substr(1) }  to find word
                bool flag = searchUtil(frontNode, word.substr(1));
                if(flag)
                    return true;
            }
        }
        else{
            int index = word[0] - 'a';
            TrieNode* child;

            if(root->children[index] != NULL)     // means word[0] th character is present
                child = root->children[index];
            else
                return false;
            return searchUtil(child, word.substr(1));
        }
        return false;
    }
    bool search(string word) {
        return searchUtil(root, word);
    }
};