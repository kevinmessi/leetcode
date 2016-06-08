#include <iostream>
#include <vector>

#include "../toolkit/print.h"

using namespace std;

//Given a list of unique words.
//Find all pairs of distinct indices (i, j) in the given list,
//so that the concatenation of the two words,
//i.e. words[i] + words[j] is a palindrome.
vector<vector<int>> palindromePairs(vector<string> &words)
{
    vector<vector<int>> pairs;
    return pairs;
}

int main()
{
//    Example 1:
//    Given words = ["bat", "tab", "cat"]
//    Return [[0, 1], [1, 0]]
//    The palindromes are ["battab", "tabbat"]
//    Example 2:
//    Given words = ["abcd", "dcba", "lls", "s", "sssll"]
//    Return [[0, 1], [1, 0], [3, 2], [2, 4]]
//    The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
    vector<string> words{ "bat", "tab", "cat" };
    PrintMatrix(palindromePairs(words));
    words = { "abcd", "dcba", "lls", "s", "sssll" };
    PrintMatrix(palindromePairs(words));
    return 0;
}
