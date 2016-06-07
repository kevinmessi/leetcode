#include <cmath>
#include <iostream>
#include <vector>

#include "../toolkit/print.h"

using namespace std;

string justifyLine(const vector<string> &words, int begin, int end, int spaces, int maxWidth)
{
    string line = words[begin];
    int slots = end - begin;
    for (int i = begin + 1; i <= end; ++i)
    {
        int n = (int)ceil((double)spaces / (double)slots);
        line.append(n, ' ').append(words[i]);
        spaces -= n;
        --slots;
    }
    if (begin == end) line.append(maxWidth - line.length(), ' ');
    return line;
}

vector<string> fullJustify1(vector<string> &words, int maxWidth)
{
    vector<string> text;
    int len = words.size();
    if (len == 0) return text;
    int width = words[0].length(), i = 1, j = 0;
    for (; i < len; ++i)
    {
        width += 1 + words[i].size();
        if (width > maxWidth)
        {
            int spaces = maxWidth - (width - words[i].size() - (i - j));
            text.push_back(justifyLine(words, j, i - 1, spaces, maxWidth));
            width = words[i].size();
            j = i;
        }
    }
    string line = words[j++];
    for (; j < len; ++j)
        line.append(1, ' ').append(words[j]);
    line.append(maxWidth - line.length(), ' ');
    text.push_back(line);
    return text;
}

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    vector<string> text;
    for (size_t i = 0, k, width; i < words.size(); i += k)
    {
        for (k = 0, width = 0; i + k < words.size() && width + words[i + k].length() <= maxWidth - k; ++k)
            width += words[i + k].length();
        string line = words[i];
        for (size_t j = 1; j < k; ++j)
        {
            if (i + k >= words.size()) line.append(1, ' ');
            else line.append((maxWidth - width) / (k - 1) + (j <= (maxWidth - width) % (k - 1)), ' ');
            line.append(words[i + j]);
        }
        line.append(maxWidth - line.length(), ' ');
        text.push_back(line);
    }
    return text;
}

int main()
{
    vector<string> words{ "This", "is", "an", "example", "of", "text", "justification." };
    PrintVector(fullJustify(words, 16));
    return 0;
}
