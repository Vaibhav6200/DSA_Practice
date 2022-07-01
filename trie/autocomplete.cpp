
#include <bits/stdc++.h>
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

//     INSERTS word in Trie
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


//      Search End Node of given Word
    TrieNode* searchEndNodeUtil(TrieNode* root, string word){
        // BASE CASE
        if(word.length() == 0)
            return root;

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL)     // means word[0] th character is present
            child = root->children[index];
        else
            return NULL;
        return searchEndNodeUtil(child, word.substr(1));
    }
    TrieNode* searchEndNode(string word) {
        return searchEndNodeUtil(root, word);
    }


    void findAllWordUtil(TrieNode* root, string path, vector<string> &result){
        for(int i=0; i<26; i++){
            if(root->children[i])       /* if Node is Not Null then add in path */
            {
                TrieNode* child = root->children[i];
                char ch = child->data;
                path.push_back(ch);

                if(child->isTerminal)
                    result.push_back(path);

                findAllWordUtil(child, path, result);
                path.pop_back();
            }
        }
    }
    vector<string> findAllWord(TrieNode* myRoot, string prefix){
        vector<string> result;
        string path="";
        findAllWordUtil(myRoot, path, result);

        // adding prefix for all recommended nodes
        for(int i=0; i<result.size(); i++)
            result[i] = prefix + result[i];

        return result;
    }
};

/*
APPROACH
    for(i=1; i<=s.size(); i++)
        string prefix = s.substr(0, i);   this will give us all prefixes of string "S"
        // search end node of this prefix
        TrieNode* endNode = searchEndNode(root, prefix);
        // now print all words starting from this endNode


    NOTE: findWord function will return us all the words starting from the root node provided
    Now we just need to create all prefixes using for loop and
    call search function to Get end Node of that prefix and then
    print Function will return us all the words starting from then prefix
    push that result in our answer vector

*/



int main(){


    vector<vector<string>> ans;

    Trie* t = new Trie();

    t->insertWord("geeikistest");
    t->insertWord("geeksforgeeks");
    t->insertWord("geeksfortest");

    string s = "geeips";

    int size  = s.size();
    for(int i=1; i<=size; i++)
    {
        string prefix = s.substr(0, i);
        TrieNode* endNode = t->searchEndNode(prefix);

        vector<string> result;
        if(endNode != NULL)
            result = t->findAllWord(endNode, prefix);
        else
            result.push_back("0");
        ans.push_back(result);
    }

    for(auto i: ans){
        for(auto j: i)
            cout << j << " ";
        cout << endl;
    }


    return 0;
}


