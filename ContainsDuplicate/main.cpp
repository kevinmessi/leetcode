/*
 * Given an array of integers, find if the array contains any duplicates.
 * Your function should return true if any value appears at least twice in the array,
 * and it should return false if every element is distinct.
 */

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct LinkedNode
{
    int val;
    LinkedNode *next;
    LinkedNode(int x = 0) : val(x), next(NULL) {}
};

bool containsDuplicate(vector<int>& nums, int k)
{
    int len = nums.size();
    if(len <= 1) return false;
    int D = len;
    LinkedNode *nodes = new LinkedNode[D];
    for(int i = 0;i < len;++i)
    {
        int bucket = abs(nums[i]) % D;
        LinkedNode *node = nodes[bucket].next;
        while(node)
        {
            int j = node->val;
            if(nums[i] == nums[j]) return true;
            node = node->next;
        }
        node = nodes[bucket].next;
        nodes[bucket].next = new LinkedNode(i);
        nodes[bucket].next->next = node;
    }
    return false;
}

bool containsDuplicate2(vector<int>& nums)
{
    unordered_set<int> s;
    int len = nums.size();
    for(int i = 0;i < len;i++)
    {
        if(s.find(nums[i]) != s.end())
            return true;
        else
            s.insert(nums[i]);
    }
    return false;
}

bool containsDuplicate3(vector<int>& nums)
{
    int len = nums.size();
    if(len < 2)
        return false;
    sort(nums.begin(), nums.end());
    for(int i = 1;i < len;i++)
    {
        if(nums[i] == nums[i-1])
            return true;
    }
    return false;
}

bool containsDuplicate4(vector<int>& nums)
{
    unordered_map<int, int> um;
    int len = nums.size();
    for(int i = 0;i < len;i++)
    {
        if(++um[nums[i]] > 1)
            return true;
    }
    return false;
}

bool containsDuplicate5(vector<int>& nums)
{
    return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 2};
    cout << containsDuplicate(v) << endl;
    return 0;
}

