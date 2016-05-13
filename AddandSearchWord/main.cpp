#include <cstring>
#include <iostream>

using namespace std;

struct TrieNode
{
    bool is_end;
    TrieNode *descendants[26];
    TrieNode()
    {
        is_end = false;
        memset(descendants, 0, sizeof descendants);
    }
};

class WordDictionary
{
public:
    WordDictionary()
    {
        _root = new TrieNode();
    }

    void addWord(string word)
    {
        TrieNode *node = _root;
        for (char c : word)
        {
            if (!node->descendants[c - 'a'])
                node->descendants[c - 'a'] = new TrieNode();
            node = node->descendants[c - 'a'];
        }
        node->is_end = true;
    }

    bool search(string word)
    {
        return query(_root, word, 0, word.length() - 1);
    }

private:
    TrieNode *_root;

    bool query(TrieNode *node, const string &word, int begin, int end)
    {
        for (int i = begin; i <= end; ++i)
        {
            if (word[i] == '.')
            {
                for (int j = 0; j < 26; ++j)
                {
                    if (node->descendants[j] && query(node->descendants[j], word, i + 1, end))
                        return true;
                }
                return false;
            }
            else
            {
                node = node->descendants[word[i] - 'a'];
                if (!node) return false;
            }
        }
        return node->is_end;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
