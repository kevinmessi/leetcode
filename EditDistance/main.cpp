#include <iostream>
#include <vector>

using namespace std;

int minDistance(string word1, string word2)
{
    int n = word1.length();
    int m = word2.length();
    int distances[n+1][m+1];
    for (int i = 0;i <= n;++i) distances[i][0] = i;
    for (int j = 1;j <= m;++j) distances[0][j] = j;
    for (int i = 1;i <= n;++i)
    {
        for (int j = 1;j <= m;++j)
        {
            if (word1[i-1] == word2[j-1])
                distances[i][j] = distances[i-1][j-1];
            else
                distances[i][j] = min(min(distances[i-1][j], distances[i][j-1]), distances[i-1][j-1]) + 1;
        }
    }
    return distances[n][m];
}

int main()
{
    cout << minDistance("abcd", "bcd") << endl;
    return 0;
}

