#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    int count;
    int depth;

    TrieNode(int d) : count(0), depth(d) {}
};

class Trie
{
public:
    TrieNode *root;
    unordered_map<TrieNode *, int> nodeToDepth;

    Trie()
    {
        root = new TrieNode(0);
    }
    void insert(const string &word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (!node->children.count(c))
            {
                node->children[c] = new TrieNode(node->depth + 1);
            }
            node = node->children[c];
            node->count++;
        }
    }
    void remove(const string &word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (node->children.count(c))
            {
                node = node->children[c];
                node->count--;
            }
        }
    }

    int find_lcp(int k)
    {
        return find_util(root, k);
    }

    int find_util(TrieNode *node, int k)
    {
        int maxDepth = 0;
        for (auto it = node->children.begin(); it != node->children.end(); ++it)
        {
            char c = it->first;
            TrieNode *child = it->second;
            if (child->count >= k)
            {
                maxDepth = max(maxDepth, find_util(child, k));
            }
        }
        return max(maxDepth, node->depth);
    }
};
vector<int> longestCommonPrefix(vector<string> &words, int k)
{
    int n = words.size();
    vector<int> result(n, 0);

    if (k > n - 1)
        return result;

    Trie trie;
    for (const string &word : words)
    {
        trie.insert(word);
    }
    for (int i = 0; i < n; i++)
    {
        trie.remove(words[i]);
        result[i] = trie.find_lcp(k);
        trie.insert(words[i]);
    }
    return result;
}

int main()
{
    vector<string> words = {"dog", "racer", "car"};
    int k = 2;

    vector<int> ans = longestCommonPrefix(words, k);

    cout << "Output: ";
    for (int num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
