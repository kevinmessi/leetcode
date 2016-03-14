#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int maxProduct1(vector<string> &words)
{
    int len = words.size(), max_product = 0;
    vector<int> tags(len, 0);
    for (int i = 0; i < len; ++i)
    {
        for (char c : words[i])
            tags[i] |= 1 << (c - 'a');
        for (int j = 0; j < i; ++j)
        {
            if (!(tags[i] & tags[j]))
                max_product = max(max_product, int(words[i].length() * words[j].length()));
        }
    }
    return max_product;
}

int maxProduct2(vector<string> &words)
{
    auto comp = [](const string &s1, const string &s2){ return s1.length() > s2.length(); };
    sort(words.begin(), words.end(), comp);
    int len = words.size(), max_product = 0;
    vector<int> tags(len, 0);
    for (int i = 0; i < len; ++i)
    {
        for (char c : words[i])
            tags[i] |= 1 << (c - 'a');
    }
    for (int i = 0; i < len; ++i)
    {
        int il = words[i].length();
        if (il * il <= max_product)
            break;
        for (int j = i + 1; j < len; ++j)
        {
            int jl = words[j].length();
            if (il * jl <= max_product)
                break;
            if (!(tags[i] & tags[j]))
                max_product = max(max_product, il * jl);
        }
    }
    return max_product;
}

int maxProduct3(vector<string> &words)
{
    unordered_map<int, int> maxlen;
    int max_product = 0;
    for (string &word : words)
    {
        int mask = 0;
        for (char c : word)
            mask |= 1 << (c - 'a');
        maxlen[mask] = max(maxlen[mask], int(word.length()));
    }
    for (auto &a : maxlen)
    {
        for (auto &b : maxlen)
        {
            if (!(a.first & b.first))
                max_product = max(max_product, a.second * b.second);
        }
    }
    return max_product;
}

int maxProduct(vector<string> &words)
{
    unordered_map<int, int> maxlen;
    int max_product = 0;
    for (string &word : words)
    {
        int mask = 0;
        for (char c : word)
            mask |= 1 << (c - 'a');
        for (auto &p : maxlen)
        {
            if (!(mask & p.first))
                max_product = max(max_product, p.second * int(word.length()));
        }
        maxlen[mask] = max(maxlen[mask], int(word.length()));
    }
    return max_product;
}

int main()
{
    vector<string> words{ "", "", "" };
    cout << maxProduct(words) << endl;
    return 0;
}

