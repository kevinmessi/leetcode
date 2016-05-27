#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int query(const vector<int> &tree, int i)
{
    int idx = i + 1, sum = 0;
    while (idx > 0)
    {
        sum += tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

void add(vector<int> &tree, int i, int val)
{
    int len = tree.size(), idx = i + 1;
    while (idx < len)
    {
        tree[idx] += val;
        idx += idx & (-idx);
    }
}

int countRangeSum1(vector<int> &nums, int lower, int upper)
{
    int len = nums.size(), count = 0;
    vector<long long> sums(len + 1, 0);
    for (int i = 0; i < len; ++i)
        sums[i + 1] = sums[i] + nums[i];
    vector<long long> sorted_sums(sums);
    sort(sorted_sums.begin(), sorted_sums.end());
    unordered_map<long long, int> indices;
    for (int i = 0; i <= len; ++i)
        indices[sorted_sums[i]] = i;
    vector<int> tree(len + 2, 0);
    for (int i = 0; i <= len; ++i)
    {
        int first = lower_bound(sorted_sums.begin(), sorted_sums.end(), sums[i] - upper) - sorted_sums.begin();
        int last = upper_bound(sorted_sums.begin(), sorted_sums.end(), sums[i] - lower) - sorted_sums.begin();
        count += query(tree, last - 1);
        count -= query(tree, first - 1);
        add(tree, indices[sums[i]], 1);
    }
    return count;
}

struct BSTNode
{
    long long val;
    int cnt, sum;
    BSTNode *left, *right;
    BSTNode(long long x) : val(x), cnt(1), sum(0), left(NULL), right(NULL){	}
};

BSTNode *insert(BSTNode *root, long long x)
{
    if (!root)
        root = new BSTNode(x);
    else if (x == root->val)
        ++root->cnt;
    else if (x > root->val)
        root->right = insert(root->right, x);
    else
    {
        ++root->sum;
        root->left = insert(root->left, x);
    }
    return root;
}

int CountLower(BSTNode *root, long long x, bool closed)
{
    if (!root)
        return 0;
    if (x == root->val)
        return root->sum + (closed ? root->cnt : 0);
    if (x < root->val)
        return CountLower(root->left, x, closed);
    return root->cnt + root->sum + CountLower(root->right, x, closed);
}

int countRangeSum2(vector<int> &nums, int lower, int upper)
{
    int len = nums.size(), count = 0;
    BSTNode *root = new BSTNode(0);
    long long sum = 0;
    for (int i = 0; i < len; ++i)
    {
        sum += nums[i];
        count += CountLower(root, sum - lower, true) - CountLower(root, sum - upper, false);
        root = insert(root, sum);
    }
    return count;
}

int MergeSort(vector<long long> &sums, int left, int right, int lower, int upper)
{
    if (left >= right) return 0;
    int middle = left + (right - left) / 2;
    int count = MergeSort(sums, left, middle, lower, upper)
            + MergeSort(sums, middle + 1, right, lower, upper);
    vector<long long> result;
    result.reserve(right - left + 1);
    int j = middle + 1, k = j, p = j;
    for (int i = left; i <= middle; ++i)
    {
        while (j <= right && sums[j] - sums[i] < lower)
            ++j;
        while (k <= right && sums[k] - sums[i] <= upper)
            ++k;
        while (p <= right && sums[p] < sums[i])
            result.push_back(sums[p++]);
        result.push_back(sums[i]);
        count += k - j;
    }
    move(result.begin(), result.end(), sums.begin() + left);
    return count;
}

int countRangeSum(vector<int> &nums, int lower, int upper)
{
    int len = nums.size();
    vector<long long> sums(len + 1, 0);
    for (int i = 0; i < len; ++i)
        sums[i + 1] = sums[i] + nums[i];
    return MergeSort(sums, 0, len, lower, upper);;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
