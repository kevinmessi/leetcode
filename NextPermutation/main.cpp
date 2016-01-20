#include <iostream>
#include <vector>

#include "../toolkit/print.h"

using namespace std;

void nextPermutation(vector<int>& nums)
{

}

int main()
{
    vector<int> nums{ 1, 2, 3 };
    PrintVector(nums);
    nextPermutation(nums);
    PrintVector(nums);
    return 0;
}

