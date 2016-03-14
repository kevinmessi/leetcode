#include <iostream>
#include <vector>
#include <queue>

#include "../toolkit/data_structure.h"

using namespace std;

void heapify(vector<ListNode*> &heap, int heap_size, int i)
{
    int left = 2 * i + 1, right = 2 * i + 2, smallest = i;
    if (left < heap_size && heap[i]->val > heap[left]->val) smallest = left;
    if (right < heap_size && heap[smallest]->val > heap[right]->val) smallest = right;
    if (i != smallest)
    {
        swap(heap[smallest], heap[i]);
        heapify(heap, heap_size, smallest);
    }
}

ListNode* mergeKLists1(vector<ListNode*> &lists)
{
    ListNode dummy(0);
    ListNode *node = &dummy;
    vector<ListNode*> heap;
    for (auto node : lists)
        if (node) heap.push_back(node);
    int heap_size = heap.size();
    for (int i = heap_size / 2 - 1; i >= 0; --i)
        heapify(heap, heap_size, i);
    while (heap_size > 0)
    {
        node->next = heap.front();
        node = node->next;
        if (node->next == NULL)
        {
            --heap_size;
            swap(heap[0], heap[heap_size]);
        }
        else
        {
            heap[0] = node->next;
        }
        heapify(heap, heap_size, 0);
    }
    return dummy.next;
}

ListNode* mergeKLists2(vector<ListNode*> &lists)
{
    ListNode dummy(0);
    ListNode *node = &dummy;
    vector<ListNode*> heap;
    for (auto node : lists)
        if (node) heap.push_back(node);
    auto comp = [](ListNode *l1, ListNode *l2) { return l1->val >= l2->val; };
    make_heap(heap.begin(), heap.end(), comp);
    while (heap.size() > 0)
    {
        node->next = heap.front();
        pop_heap(heap.begin(), heap.end(), comp);
        heap.pop_back();
        node = node->next;
        if (node->next)
        {
            heap.push_back(node->next);
            push_heap(heap.begin(), heap.end(), comp);
        }
    }
    return dummy.next;
}

struct comp
{
    bool operator()(const ListNode *l1, const ListNode *l2)
    {
        return l1->val >= l2->val;
    }
};

ListNode* mergeKLists3(vector<ListNode*> &lists)
{
    ListNode dummy(0);
    ListNode *node = &dummy;
    priority_queue<ListNode*, vector<ListNode*>, comp> pq;
    for (auto node : lists)
        if (node) pq.push(node);
    while (!pq.empty())
    {
        node->next = pq.top();
        pq.pop();
        node = node->next;
        if (node->next) pq.push(node->next);
    }
    return dummy.next;
}

ListNode* merge2Lists(ListNode *l1, ListNode *l2)
{
    ListNode dummy(0);
    ListNode *node = &dummy;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            node->next = l1;
            l1 = l1->next;
        }
        else
        {
            node->next = l2;
            l2 = l2->next;
        }
        node = node->next;
    }
    node->next = l1 ? l1 : l2;
    return dummy.next;
}

ListNode* mergeKLists(const vector<ListNode*> &lists, int begin, int end)
{
    if (begin > end) return NULL;
    if (begin == end) return lists[begin];
    int mid = begin + (end - begin) / 2;
    return merge2Lists(mergeKLists(lists, begin, mid), mergeKLists(lists, mid + 1, end));
}

ListNode* mergeKLists(vector<ListNode*> &lists)
{
    return mergeKLists(lists, 0, lists.size() - 1);
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

