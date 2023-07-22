#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for(int i = 0 ; i<26 ; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root , string word)
    {
        //base case
        if(word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0]-'A';
        TrieNode* child;

        //present
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
           //absent
           child = new TrieNode(word[0]);
           root->children[index] = child; 
        }
        //recursion
        insertUtil(child,word.substr(1));
    }
    //insert
    void insertWord(string word)
    {
        insertUtil(root,word);   
    }
    
    //search
    bool searchUtil(TrieNode* root , string word)
    {
        if(word.length() == 0)
        {
            //is the last character is terminal character
            return root->isTerminal;
        }
        int index = word[0]-'A';
        TrieNode* child;

        //if character is present in trie
        if(root->children[index] != nullptr)
        {
            child = root->children[index];
        }
        else
        {
            //absent
            return false;
        }
        return searchUtil(child,word.substr(1));
    }
    bool searchWord(string word)
    {
        return searchUtil(root,word);
    }

    void removeWordUtil(TrieNode* root , string word)
    {
        if(word.length() == 0)
        {
            root->isTerminal = false;
            return ;
        }
        int index = word[0]-'A';
        TrieNode* child;

        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return;
        }
        removeWordUtil(child,word.substr(1));
    }

    void removeWord(string word)
    {
         removeWordUtil(root,word);
    }
};

int main()
{
    Trie *t = new Trie();
    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");
    cout<<"Present or not "<<t->searchWord("ARM")<<endl;
    cout<<"Present or not "<<t->searchWord("ARMY")<<endl;
    cout<<"Present or not "<<t->searchWord("TIM")<<endl;
    t->removeWord("ARM");
     cout<<"Present or not "<<t->searchWord("ARM")<<endl;
     t->insertWord("ARM");
      cout<<"Present or not "<<t->searchWord("ARM")<<endl;
    return 0;
}