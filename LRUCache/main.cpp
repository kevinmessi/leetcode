#include <iostream>
#include <unordered_map>

using namespace std;

struct DoubleListNode
{
    const int key;
    int value;
    DoubleListNode *pre;
    DoubleListNode *next;
    DoubleListNode(int k, int v) : key(k), value(v), pre(NULL), next(NULL) {}
};

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        capacity_ = capacity;
        head_ = new DoubleListNode(0, 0);
        head_->next = head_;
        head_->pre = head_;
    }

    ~LRUCache()
    {
        DoubleListNode *node = head_->next;
        while (node->value)
        {
            DoubleListNode *temp = node->next;
            delete node;
            node = temp;
        }
        delete head_;
    }

    int get(int key)
    {
        if (table_.find(key) == table_.end()) return -1;
        DoubleListNode *node = table_[key];
        RemoveNode(node);
        AdvanceNode(node);
        return node->value;
    }

    void set(int key, int value)
    {
        if (table_.find(key) == table_.end())
        {
            DoubleListNode *node = new DoubleListNode(key, value);
            AdvanceNode(node);
            table_[key] = node;
            if ((int)table_.size() > capacity_)
            {
                DoubleListNode *least = head_->pre;
                RemoveNode(least);
                table_.erase(least->key);
                delete least;
            }
        }
        else
        {
            DoubleListNode *node = table_[key];
            node->value = value;
            RemoveNode(node);
            AdvanceNode(node);
        }
    }

private:
    int capacity_;
    DoubleListNode *head_;
    unordered_map<int, DoubleListNode *> table_;

    void RemoveNode(DoubleListNode *node)
    {
        node->next->pre = node->pre;
        node->pre->next = node->next;
    }

    void AdvanceNode(DoubleListNode *node)
    {
        node->next = head_->next;
        node->next->pre = node;
        node->pre = head_;
        node->pre->next = node;
    }
};

int main()
{
    // 2,[set(2,1),set(1,1),set(2,3),set(4,1),get(1),get(2)]
    LRUCache cache(2);
    cache.set(2, 1);
    cache.set(1, 1);
    cache.set(2, 3);
    cache.set(4, 1);
    cout << cache.get(1) << endl;
    cout << cache.get(2) << endl;
    return 0;
}
