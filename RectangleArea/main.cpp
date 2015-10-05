#include <iostream>

using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
    int total = (C - A) * (D - B) + (G - E) * (H - F), overlap = 0;
    if(G > A && E < C && F < D && H > B) overlap = (min(C, G) - max(A, E)) * (min(D, H) - max(B, F));
    return total - overlap;
}

int main()
{
    cout << computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
    return 0;
}

