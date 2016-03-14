#include <cstring>
#include <iostream>

using namespace std;

class TrieNode
{
public:
    bool is_end;
    TrieNode *descendants[26];

    // Initialize your data structure here.
    TrieNode()
    {
        is_end = false;
        memset(descendants, 0, sizeof descendants);
    }
};

class Trie
{
public:
    Trie()
    {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (node->descendants[c - 'a'] == NULL)
                node->descendants[c - 'a'] = new TrieNode();
            node = node->descendants[c - 'a'];
        }
        node->is_end = true;
    }

    // Returns if the word is in the trie.
    bool search(string word)
    {
        TrieNode *node = find(word);
        return node != NULL && node->is_end;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix)
    {
        return find(prefix) != NULL;
    }

private:
    TrieNode* root;

    TrieNode *find(string s)
    {
        TrieNode *node = root;
        int len = s.length();
        for (int i = 0; i < len && node != NULL; ++i)
            node = node->descendants[s[i] - 'a'];
        return node;
    }
};

int main()
{
    Trie trie;
    trie.insert("abc");
    cout << trie.search("abc") << endl;
    cout << trie.search("ab") << endl;
    trie.insert("ab");
    cout << trie.search("ab") << endl;
    trie.insert("ab");
    cout << trie.search("ab") << endl;
    cout << trie.startsWith("a") << endl;
    return 0;
}

