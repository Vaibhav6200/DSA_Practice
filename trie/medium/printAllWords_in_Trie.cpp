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

class Trie {
public:
    TrieNode* root;
    Trie() {
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
    void insertWord(string word) {
        insertUtil(root, word);
    }


    bool searchUtil(TrieNode* root, string word){
        // BASE CASE
        if(word.length() == 0)
            return root->isTerminal;

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL)     // means word[0] th character is present
            child = root->children[index];
        else
            return false;
        return searchUtil(child, word.substr(1));
    }
    bool search(string word) {
        return searchUtil(root, word);
    }

    void printAllWords(TrieNode* root, string path, vector<string> &result){

        for(int i=0; i<26; i++){
            if(root->children[i])       /* if Node is Not Null then add in path */
            {
                TrieNode* child = root->children[i];
                char ch = child->data;
                path.push_back(ch);     // add non null word in path

                // cout << path << endl;

                if(child->isTerminal)
                    result.push_back(path);

                printAllWords(child, path, result);
                path.pop_back();
            }
        }
    }
    void print(){
        vector<string> result;
        string path="";
        printAllWords(root, path, result);

        for(int i=0; i<result.size(); i++)
            cout << result[i] << " ";
        cout << endl;
    }
};


int main()
{
    Trie* t = new Trie();
    t->insertWord("abcd");
    t->insertWord("dcba");
    t->insertWord("lls");
    t->insertWord("s");
    t->insertWord("sssll");
    t->print();

    return 0;
}