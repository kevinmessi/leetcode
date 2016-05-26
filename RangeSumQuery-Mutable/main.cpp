#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class NumArray1
{
public:
    NumArray1(vector<int> &nums)
    {
        int len = nums.size();
        tree_ = vector<int>(len + 1, 0);
        for (int i = 0; i < len; ++i)
            add(i, nums[i]);
    }

    void update(int i, int val)
    {
        add(i, val - get(i));
    }

    int sumRange(int i, int j)
    {
        return accumulate(j) - accumulate(i - 1);
    }

private:
    vector<int> tree_;

    int accumulate(int i)
    {
        int sum = 0, idx = i + 1;
        while (idx > 0)
        {
            sum += tree_[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }

    void add(int i, int delta)
    {
        int idx = i + 1, len = tree_.size();
        while (idx < len)
        {
            tree_[idx] += delta;
            idx += idx & (-idx);
        }
    }

    int get(int i)
    {
        int idx = i + 1, sum = tree_[idx], z = idx - (idx & (-idx));
        while (i != z)
        {
            sum -= tree_[i];
            i -= i & (-i);
        }
        return sum;
    }
};

class NumArray2
{
public:
    NumArray2(vector<int> &nums)
    {
        nums_ = nums;
        int len = nums.size();
        block_size_ = max(1, (int)sqrt(len)), block_num_ = len / block_size_;
        block_ = vector<int>(block_num_, 0);
        for (int i = 0; i < block_num_; ++i)
        {
            int block_start = i * block_size_;
            for (int j = 0; j < block_size_; ++j)
                block_[i] += nums[block_start + j];
        }
    }

    void update(int i, int val)
    {
        int i_block = i / block_size_;
        if (i_block < block_num_)
            block_[i_block] += val - nums_[i];
        nums_[i] = val;
    }

    int sumRange(int i, int j)
    {
        int sum = 0, begin = i / block_size_, end = (j + 1) / block_size_ - 1;
        for (int k = begin; k <= end; ++k)
            sum += block_[k];
        for (int k = block_size_ * begin; k < i; ++k)
            sum -= nums_[k];
        for (int k = (end + 1) * block_size_; k <= j; ++k)
            sum += nums_[k];
        return sum;
    }

private:
    int block_size_, block_num_;
    vector<int> nums_;
    vector<int> block_;
};

class NumArray
{
public:
    NumArray(vector<int> &nums)
    {
        int len = nums.size();
        tree_ = vector<int>(2 * len);
        for (int i = len, j = 0; j < len; ++i, ++j)
            tree_[i] = nums[j];
        for (int i = len - 1; i > 0; --i)
            tree_[i] = tree_[2 * i] + tree_[2 * i + 1];
    }

    void update(int i, int val)
    {
        int idx = i + tree_.size() / 2, delta = val - tree_[idx];
        while (idx > 0)
        {
            tree_[idx] += delta;
            idx >>= 1;
        }
    }

    int sumRange(int i, int j)
    {
        int begin = i + tree_.size() / 2, end = j + tree_.size() / 2, sum = 0;
        while (begin <= end)
        {
            if (begin & 1)
            {
                sum += tree_[begin];
                ++begin;
            }
            if (!(end & 1))
            {
                sum += tree_[end];
                --end;
            }
            begin >>= 1;
            end >>= 1;
        }
        return sum;
    }

private:
    vector<int> tree_;
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
