#include <iostream>

using namespace std;

string reverseVowels(string s)
{
    bool is_vowel[256] = { false };
    is_vowel['a'] = is_vowel['e'] = is_vowel['i'] = is_vowel['o'] = is_vowel['u'] = true;
    is_vowel['A'] = is_vowel['E'] = is_vowel['I'] = is_vowel['O'] = is_vowel['U'] = true;
    int len = s.length(), i = 0, j = len - 1;
    while (true)
    {
        while (i < j && !is_vowel[s[i]])
            ++i;
        while (j > i && !is_vowel[s[j]])
            --j;
        if (i < j) swap(s[i++], s[j--]);
        else break;
    }
    return s;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
