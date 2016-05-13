#include <iostream>
#include <queue>

using namespace std;

class MedianFinder
{
public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        if (small_q.empty() || small_q.top() <= num) large_q.push(-num);
        else small_q.push(num);
        if (small_q.size() < large_q.size())
        {
            small_q.push(-large_q.top());
            large_q.pop();
        }
        else if (small_q.size() > large_q.size() + 1)
        {
            large_q.push(-small_q.top());
            small_q.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian()
    {
        return small_q.size() > large_q.size()
                ? small_q.top()
                : (small_q.top() - large_q.top()) / 2.0;
    }
private:
    priority_queue<long long> small_q, large_q;
};

int main()
{
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << endl;
    mf.addNum(3);
    cout << mf.findMedian() << endl;
    return 0;
}
