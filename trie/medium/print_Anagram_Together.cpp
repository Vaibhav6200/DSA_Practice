#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    vector<string> anagram;

    TrieNode(char ch){
        data = ch;
        isTerminal = false;

        for(int i=0; i<26; i++)
            children[i] = NULL;
    }
};


class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, int idx, vector<string> string_list, string word){
        if(word.length() == 0){
            // if True: means its leaf node (so maintain list)
            root->isTerminal = true;
            root->anagram.push_back(string_list[idx]);
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
        insertUtil(child, idx, string_list, word.substr(1));
    }
    void insertWord(string word, int idx, vector<string> string_list){
        insertUtil(root, idx, string_list, word);
    }


    // Trie Traversal
    void findUtil(TrieNode* root, vector<vector<string>> &result){

        for(int i=0; i<26; i++)
        {
            if(root->children[i]){
                TrieNode* child = root->children[i];

                if(child->isTerminal)
                    result.push_back(child->anagram);

                findUtil(child, result);
            }
        }
    }
    vector<vector<string>> findAllAnagrams(){
        vector<vector<string>> temp;       // this temp contains index of anagrams
        findUtil(root, temp);

        return temp;
    }
};


int main()
{
    vector<string> string_list;
    string_list.push_back("act");
    string_list.push_back("god");
    string_list.push_back("cat");
    string_list.push_back("dog");
    string_list.push_back("tac");


    vector<vector<string>> ans;
    Trie* t = new Trie();

    int n = string_list.size();
    for(int i=0; i<n; i++){

        // Step1: copy string in local buffer
        string temp = string_list[i];

        // Step2: sort local copy of string
        sort(temp.begin(), temp.end());

        // Step3: insert that copy of string in trie along with its index
        t->insertWord(temp, i, string_list);
    }

    // Step4: go to all leaf Nodes of trie (it will contain vector of all anagrams)
    vector<vector<string>> temp = t->findAllAnagrams();

    for(auto i: temp){
        for(auto j: i)
            cout << j << " ";
        cout << endl;
    }


    return 0;
}