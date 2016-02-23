#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int ladderLength1(string beginWord, string endWord, unordered_set<string> &wordList)
{
    int len = 1;
    wordList.insert(endWord);
    queue<string> words;
    words.push(beginWord);
    while (!words.empty())
    {
        int n = words.size();
        for (int i = 0; i < n; ++i)
        {
            string word = words.front();
            words.pop();
            if (word == endWord) return len;
            for (size_t j = 0; j < word.size(); ++j)
            {
                char c = word[j];
                for (char letter = 'a'; letter <= 'z'; ++letter)
                {
                    word[j] = letter;
                    auto pos = wordList.find(word);
                    if (pos != wordList.end())
                    {
                        words.push(word);
                        wordList.erase(pos);
                    }
                }
                word[j] = c;
            }
        }
        ++len;
    }
    return 0;
}

int ladderLength(string beginWord, string endWord, unordered_set<string> &wordList)
{
    unordered_set<string> head, tail, *phead, *ptail;
    head.insert(beginWord);
    tail.insert(endWord);
    int len = 2;
    while (!head.empty() && !tail.empty())
    {
        if (head.size() < tail.size())
        {
            phead = &head;
            ptail = &tail;
        }
        else
        {
            phead = &tail;
            ptail = &head;
        }
        unordered_set<string> temp;
        for (auto word : *phead)
        {
            for (size_t j = 0; j < word.length(); ++j)
            {
                char c = word[j];
                for (char letter = 'a'; letter <= 'z'; ++letter)
                {
                    word[j] = letter;
                    if (ptail->find(word) != ptail->end())
                        return len;
                    if (wordList.find(word) != wordList.end())
                    {
                        temp.insert(word);
                        wordList.erase(word);
                    }
                }
                word[j] = c;
            }
        }
        ++len;
        *phead = temp;
    }
    return 0;
}

int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    unordered_set<string> wordList;
    wordList.insert("hot");
    wordList.insert("dot");
    wordList.insert("dog");
    wordList.insert("lot");
    wordList.insert("log");
    cout << ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}

