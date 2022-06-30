#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char c){
        data = c;
        isTerminal = false;

        for(int i=0; i<26; i++)     // Initializing all 26 child nodes to NULL
            children[i] = NULL;
    }
};

class Trie{

public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }


    void insertUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        // Assumption: word has only capital letters
        int index = word[0] - 'A';
        TrieNode* child;

        // char present
        if(root->children[index] != NULL)
            child = root->children[index];

        // Absent
        else{
            child = new TrieNode(word[0]);      // if character not present then create it
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }


    bool searchUtil(TrieNode* root, string word){
        // Base case
        if(word.length() == 0)
            return root->isTerminal;

        // Assumption: All characters in CAPS
        int index = word[0] - 'A';
        TrieNode* child;

        // searching word 0th character present
        if(root->children[index] != NULL)
            child = root->children[index];

        // absent
        else
            return false;

        // Recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word){
        return searchUtil(root, word);
    }

};


int main()
{
    Trie* t = new Trie();
    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");

    cout << "Present or Not : " << t->searchWord("TIME") << endl;
    cout << "Present or Not : " << t->searchWord("TIM") << endl;

    return 0;
}