#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> countSmaller1(vector<int> &nums)
{
    int len = nums.size();
    vector<int> counts(len);
    vector<int> right_nums;
    for (int i = len - 1; i >= 0; --i)
    {
        auto pos = lower_bound(right_nums.begin(), right_nums.end(), nums[i]);
        counts[i] = pos - right_nums.begin();
        right_nums.insert(pos, nums[i]);
    }
    return counts;
}

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

vector<int> countSmaller2(vector<int> &nums)
{
    int len = nums.size();
    unordered_map<int, int> index;
    vector<int> counts(nums);
    vector<int> tree(len + 1, 0);
    sort(counts.begin(), counts.end());
    for (int i = 0; i < len; ++i)
        index[counts[i]] = i;
    for (int i = len - 1; i >= 0; --i)
    {
        counts[i] = query(tree, index[nums[i]] - 1);
        add(tree, index[nums[i]], 1);
    }
    return counts;
}

struct BSTNode
{
    int val, sum, cnt;
    BSTNode *left, *right;
    BSTNode(int x) : val(x), sum(0), cnt(1), left(NULL), right(NULL) {}
};

BSTNode *insert(BSTNode *root, int num, int pre_sum, int &count)
{
    if (!root)
    {
        root = new BSTNode(num);
        count = pre_sum;
    }
    else if (num == root->val)
    {
        ++root->cnt;
        count = root->sum + pre_sum;
    }
    else if (num < root->val)
    {
        ++root->sum;
        root->left = insert(root->left, num, pre_sum, count);
    }
    else
    {
        root->right = insert(root->right, num, pre_sum + root->sum + root->cnt, count);
    }
    return root;
}

vector<int> countSmaller3(vector<int> &nums)
{
    vector<int> counts(nums.size());
    BSTNode *root = NULL;
    for (int i = nums.size() - 1; i >= 0; --i)
        root = insert(root, nums[i], 0, counts[i]);
    return counts;
}

void MergeSort(vector<int> &nums, vector<int> &indices, int left, int right, vector<int> &counts)
{
    if (left >= right) return;
    int middle = left + (right - left) / 2;
    MergeSort(nums, indices, left, middle, counts);
    MergeSort(nums, indices, middle + 1, right, counts);
    vector<int> result;
    result.reserve(right - left + 1);
    int i = left, j = middle + 1, cnt = 0;
    while (i <= middle || j <= right)
    {
        if (j > right || i <= middle && nums[indices[i]] <= nums[indices[j]])
        {
            counts[indices[i]] += cnt;
            result.push_back(indices[i++]);
        }
        else
        {
            ++cnt;
            result.push_back(indices[j++]);
        }
    }
    move(result.begin(), result.end(), indices.begin() + left);
}

vector<int> countSmaller4(vector<int> &nums)
{
    int len = nums.size();
    vector<int> counts(len, 0), indices(len);
    iota(indices.begin(), indices.end(), 0);
    MergeSort(nums, indices, 0, len - 1, counts);
    return counts;
}

void countSmaller(const vector<int> &nums, vector<int> &indices, int left, int right, int mask, vector<int> &counts)
{
    if (!mask || left >= right) return;
    int flag = mask < 0 ? 0 : mask;
    vector<int> low, high;
    for (int i = left; i <= right; ++i)
    {
        if ((nums[indices[i]] & mask) == flag)
        {
            high.push_back(indices[i]);
            counts[indices[i]] += low.size();
        }
        else
        {
            low.push_back(indices[i]);
        }
    }
    move(high.begin(), high.end(), indices.begin() + left);
    move(low.begin(), low.end(), indices.begin() + left + high.size());
    countSmaller(nums, indices, left, left + high.size() - 1, (unsigned)mask >> 1, counts);
    countSmaller(nums, indices, left + high.size(), right, (unsigned)mask >> 1, counts);
}

vector<int> countSmaller(vector<int> &nums)
{
    int len = nums.size();
    vector<int> counts(len, 0), indices(len);
    iota(indices.rbegin(), indices.rend(), 0);
    countSmaller(nums, indices, 0, len - 1, 1 << 31, counts);
    return counts;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
