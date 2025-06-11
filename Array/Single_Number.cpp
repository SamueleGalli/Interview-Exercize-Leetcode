#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
class Solution
{
public:
    int singleNumber(std::vector<int> &nums)
    {
        std::unordered_set<int> with_dup;
        if (nums.size() == 1)
            return(nums[0]);
        for (size_t i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            if (with_dup.count(num))
                with_dup.erase(num);
            else
                with_dup.insert(num);

        }
        return(*with_dup.begin());
    }
};