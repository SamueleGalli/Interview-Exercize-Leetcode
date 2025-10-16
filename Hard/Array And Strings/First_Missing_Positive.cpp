#include <vector>
#include <unordered_set>
#include <limits.h>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        unordered_set<int> better_nums;
        for (size_t i = 0;i < nums.size();i++)
        {
            if (nums[i] <= 0)
                continue;
            better_nums.insert(nums[i]);
        }
        int i = 1;
        for (;i < INT_MAX;i++)
        {
            if (better_nums.count(i) == 0)
                break;
        }
        return (i);
    }
};