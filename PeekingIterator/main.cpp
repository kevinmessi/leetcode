#include <iostream>
#include <vector>

using namespace std;

class Iterator
{
    struct Data;
    Data *data;
public:
    Iterator(const vector<int> &nums);
    Iterator(const Iterator &iter);
    virtual ~Iterator();
    int next();
    bool hasNext() const;
};


class PeekingIterator1 : public Iterator
{
private:
    int peek_element;
    bool has_next;
public:
    PeekingIterator1(const vector<int> &nums) : Iterator(nums)
    {
        has_next = Iterator::hasNext();
        if (has_next) peek_element = Iterator::next();
    }

    int peek()
    {
        return peek_element;
    }

    int next()
    {
        int next_element = peek_element;
        has_next = Iterator::hasNext();
        if (has_next) peek_element = Iterator::next();
        return next_element;
    }

    bool hasNext() const
    {
        return has_next;
    }
};

class PeekingIterator2 : public Iterator
{
private:
    int peek_element;
    bool has_peeked;
public:
    PeekingIterator2(const vector<int> &nums) : Iterator(nums)
    {
        has_peeked = false;
    }

    int peek()
    {
        if (!has_peeked)
        {
            peek_element = Iterator::next();
            has_peeked = true;
        }
        return peek_element;
    }

    int next()
    {
        if (!has_peeked) return Iterator::next();
        has_peeked = false;
        return peek_element;
    }

    bool hasNext() const
    {
        return has_peeked || Iterator::hasNext();
    }
};

class PeekingIterator : public Iterator
{
public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums)
    {
    }

    int peek()
    {
        return Iterator(*this).next();
    }

    int next()
    {
        return Iterator::next();
    }

    bool hasNext() const
    {
        return Iterator::hasNext();
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
