// CODE STUDIO PROBLEM: IMPLEMENT TRIE II

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
        for(int i=0; i<26; i++)
            children[i] = NULL;
    }
};

class Trie{
    TrieNode* root;
    public:

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){
        if(word.length() == 0)
            root->isTerminal = true;
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
    void insert(string &word){
        insertUtil(root, word);
    }


    void countWordUtil(TrieNode* root, string org, string word, int &count){
        if((word.length() == 0) && (root->isTerminal == true))
            count++;           // checking 'M' is Terminal or not in word "TIM"

        else{
            int index = word[0] - 'a';
            TrieNode* child;
            if(root->children[index] != NULL){
                child = root->children[index];
                countWordUtil(child, org, word.substr(1), count);
            }
        }

        // checking if intermediate node contains word "TIM"
        int idx = org[0] - 'a';
        if(root->children[idx] != NULL) // means TIM is also present in intermediate node
            countWordUtil(root->children[idx], org, org.substr(1), count);

        /*
    APPROACH:
            search for word[0] in root children
            if(found) recursively check for word[1]

            At last (BASE CASE)
                when word.length == 0
                check(if root->isTerminal == true) count++;    // word found
            else{
                 int index = word[0] - 'a';
                 TrieNode* child;
                 if(root->children[index] != NULL)    // means 'T' present for TIM
                     child = root->children[index];
                 else
                     return;
                 countWordUtil(child, word.substr(1));
            }


             // checking if intermediate node contains word "TIM"
             int idx = org[0] - 'a';
             if(root->children[idx] != NULL){ // means TIM is also present in intermediate node
                 countWordUtil(root->children[idx], org.substr(1));
             }

        */
    }
    int countWordsEqualTo(string &word){
        int count=0;
        countWordUtil(root, word, word, count);
        return count;
    }


    int countPrefixUtil(TrieNode* root, string word){
        if(word.length() == 0){
            int count=0;        // stores count of word having given : "PREFIX"
            for(int i=0; i<26; i++){
                if(root->children[i] != NULL)
                    count++;
            }
            return count;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index] != NULL)
            child = root->children[index];
        else
            return 0;
        return countPrefixUtil(child, word.substr(1));
    }
    int countWordsStartingWith(string &word){
        return countPrefixUtil(root, word);
    }

    void eraseUtil(TrieNode* root, string word){
        if(word.length() == 0)
            root->isTerminal = false;
        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index] != NULL)
            child = root->children[index];
        else
            return;  // if this executes then word D.N.E.
        eraseUtil(child, word.substr(1));
    }
    void erase(string &word){
        eraseUtil(root, word);
    }
};



int main()
{

    return 0;
}