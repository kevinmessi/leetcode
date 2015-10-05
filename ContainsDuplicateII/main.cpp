//Given an array of integers and an integer k, find out whether there are
//two distinct indices i and j in the array such that nums[i] = nums[j] and
//the difference between i and j is at most k.

#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct LinkedNode
{
    int val;
    LinkedNode *next;
    LinkedNode(int x = 0) : val(x), next(NULL) {}
};

bool containsNearbyDuplicate(vector<int>& nums, int k)
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
            if(nums[i] == nums[j] && i - j <= k) return true;
            node = node->next;
        }
        node = nodes[bucket].next;
        nodes[bucket].next = new LinkedNode(i);
        nodes[bucket].next->next = node;
    }
    return false;
}

//Sliding window
bool containsNearbyDuplicate2(vector<int>& nums, int k)
{
    set<int> cand;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        if (i > k) cand.erase(nums[i-k-1]);
        if (!cand.insert(nums[i]).second) return true;
    }
    return false;
}

int main()
{
    vector<int> nums = {-1, -1};
    cout << containsNearbyDuplicate(nums, 1) << endl;
    return 0;
}

