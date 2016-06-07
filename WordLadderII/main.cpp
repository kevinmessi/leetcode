#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void FindPath(const string &begin, const string &end, unordered_map<string, vector<string>> &pre,
              vector<string> &ladder, vector<vector<string>> &ladders)
{
    if (begin == end)
    {
        ladder.push_back(end);
        ladders.emplace_back(ladder.rbegin(), ladder.rend());
        ladder.pop_back();
        return;
    }
    for (const string &word : pre[end])
    {
        ladder.push_back(end);
        FindPath(begin, word, pre, ladder, ladders);
        ladder.pop_back();
    }
}

vector<vector<string>> findLadders1(string beginWord, string endWord, unordered_set<string> &wordList)
{
    int len = beginWord.length();
    unordered_map<string, vector<string>> pre;
    unordered_set<string> head;
    head.insert(beginWord);
    wordList.insert(endWord);
    while (!head.empty())
    {
        if (head.find(endWord) != head.end()) break;
        for (const string &word : head)
            wordList.erase(word);
        unordered_set<string> words(move(head));
        for (const string &word : words)
        {
            string temp = word;
            for (int j = 0; j < len; ++j)
            {
                char c = temp[j];
                for (char letter = 'a'; letter <= 'z'; ++letter)
                {
                    temp[j] = letter;
                    if (wordList.find(temp) != wordList.end())
                    {
                        head.insert(temp);
                        pre[temp].push_back(word);
                    }
                }
                temp[j] = c;
            }
        }
    }
    vector<vector<string>> ladders;
    vector<string> ladder;
    FindPath(beginWord, endWord, pre, ladder, ladders);
    return ladders;
}

bool intersects(unordered_set<string> &set1, unordered_set<string> &set2)
{
    for (const string &s : set1)
    {
        if (set2.find(s) != set2.end())
            return true;
    }
    return false;
}

vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList)
{
    int len = beginWord.length();
    unordered_map<string, vector<string>> pre;
    unordered_set<string> head, tail, *phead;
    head.insert(beginWord);
    tail.insert(endWord);
    wordList.insert(endWord);
    while (!head.empty() && !tail.empty() && !intersects(head, tail))
    {
        bool head_first = head.size() <= tail.size();
        phead = head_first ? &head : &tail;
        for (const string &word : *phead)
            wordList.erase(word);
        unordered_set<string> words(move(*phead));
        for (const string &word : words)
        {
            string temp = word;
            for (int j = 0; j < len; ++j)
            {
                char c = temp[j];
                for (char letter = 'a'; letter <= 'z'; ++letter)
                {
                    temp[j] = letter;
                    if (wordList.find(temp) != wordList.end())
                    {
                        phead->insert(temp);
                        head_first ? pre[temp].push_back(word) : pre[word].push_back(temp);
                    }
                }
                temp[j] = c;
            }
        }
    }
    vector<vector<string>> ladders;
    vector<string> ladder;
    FindPath(beginWord, endWord, pre, ladder, ladders);
    return ladders;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
