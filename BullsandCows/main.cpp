#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

string getHint1(string secret, string guess)
{
    vector<int> secret_map(10, 0), guess_map(10, 0);
    int A = 0, B = 0, len = secret.size();
    for (int i = 0; i < len; ++i)
    {
        if (secret[i] == guess[i]) ++A;
        else
        {
            ++secret_map[secret[i] - '0'];
            ++guess_map[guess[i] - '0'];
        }
    }
    for (int i = 0; i < 10; ++i)
        B += min(secret_map[i], guess_map[i]);
    stringstream ss;
    ss << A << 'A' << B << 'B';
    return ss.str();
}

string getHint(string secret, string guess)
{
    vector<int> map(10, 0);
    int A = 0, B = 0, len = secret.size();
    for (int i = 0; i < len; ++i)
    {
        if (secret[i] == guess[i]) ++A;
        else
        {
            if (map[guess[i] - '0']-- > 0) ++B;
            if (map[secret[i] - '0']++ < 0) ++B;
        }
    }
    stringstream ss;
    ss << A << 'A' << B << 'B';
    return ss.str();
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

