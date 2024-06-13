#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (auto &child : children)
        {
            child = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{

public:
    TrieNode *root;

    void insertUtil(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // assuming that the word is in uppercase
        int index = word[0] - 'A';
        TrieNode *child;

        // if the child is not present
        if (root->children[index] == NULL)
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        else
        {
            child = root->children[index];
        }
        // recursion

        insertUtil(child, word.substr(1));
    }
    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
            child = root->children[index];
        else
            return false;

        return searchUtil(child, word);
    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }
};

int main()
{
    Trie t;
    t.root = new TrieNode('\0');
    t.insertWord("APPLE");
    return 0;
}