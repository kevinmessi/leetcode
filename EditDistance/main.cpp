#include <iostream>
#include <vector>

using namespace std;

int minDistance(string word1, string word2)
{
    int m = word1.length();
    int n = word2.length();
    vector<int> distances(n + 1, 0);
    for (int j = 0;j <= n;++j) distances[j] = j;
    for (int i = 1;i <= m;++i)
    {
        int pre = distances[0];
        distances[0] = i;
        for (int j = 1;j <= n;++j)
        {
            int temp = distances[j];
            if (word1[i-1] == word2[j-1])
                distances[j] = pre;
            else
                distances[j] = min(min(distances[j-1], distances[j]), pre) + 1;
            pre = temp;
        }
    }
    return distances[n];
}

int minDistance2(string word1, string word2)
{
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>> distances(m + 1, vector<int>(n + 1, 0));
    for (int i = 0;i <= m;++i) distances[i][0] = i;
    for (int j = 1;j <= n;++j) distances[0][j] = j;
    for (int i = 1;i <= m;++i)
    {
        for (int j = 1;j <= n;++j)
        {
            if (word1[i-1] == word2[j-1])
                distances[i][j] = distances[i-1][j-1];
            else
                distances[i][j] = min(min(distances[i-1][j], distances[i][j-1]), distances[i-1][j-1]) + 1;
        }
    }
    return distances[m][n];
}

int main()
{
    cout << minDistance("algorithm", "altruistic") << endl;
    return 0;
}

